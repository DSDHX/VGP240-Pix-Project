#include "PostProcessing.h"

PostProcessing* PostProcessing::Get()
{
    static PostProcessing sInstance;
    return &sInstance;
}

void PostProcessing::Initialize(int width, int height, const X::Color& clearColor)
{
    mClearColor = clearColor;
    mRenderTarget.Initialize(width, height, clearColor);
}

void PostProcessing::OnNewFrame()
{
    mDrawBegin = false;
}

void PostProcessing::SetEffectType(EffectTypes effectType)
{
    mEffectType = effectType;
}

void PostProcessing::BeginDraw()
{
    mDrawBegin = mEffectType != EffectTypes::None;
    if (mDrawBegin)
    {
        mRenderTarget.ClearImage(mClearColor);
    }
}

bool PostProcessing::Draw(int x, int y, const X::Color& color)
{
    if (mDrawBegin)
    {
        mRenderTarget.DrawPixel(x, y, color);
        return true;
    }
    return false;
}

void PostProcessing::EndDraw()
{
    if (mDrawBegin)
    {
        for (int y = 0; y < mRenderTarget.GetHeight(); y++)
        {
            for (int x = 0; x < mRenderTarget.GetWidth(); x++)
            {
                DrawPixel(x, y);
            }
        }
    }
    mDrawBegin = false;
}

void PostProcessing::DrawPixel(int x, int y)
{
    X::Color color = X::Colors::Black;
    switch (mEffectType)
    {
    case EffectTypes::None:
    {
        color = mRenderTarget.GetColor(x, y);
    }
    break;
    case EffectTypes::MonoChrome:
    {
        color = mRenderTarget.GetColor(x, y);
        color = (color.r + color.g + color.b) / 3.0f;
    }
    break;
    case EffectTypes::Invert:
    {
        color = mRenderTarget.GetColor(x, y);
        color.r = 1.0f - color.r;
        color.g = 1.0f - color.g;
        color.b = 1.0f - color.b;
    }
    break;
    case EffectTypes::Mirror:
    {
        color = mRenderTarget.GetColor(x, y);
        y = mRenderTarget.GetHeight() - y - 1;
    }
    break;
    case EffectTypes::ColorMaskR:
    {
        color = mRenderTarget.GetColor(x, y);
        color.r = 0.0f;
    }
    break;
    case EffectTypes::ColorMaskG:
    {
        color = mRenderTarget.GetColor(x, y);
        color.g = 0.0f;
    }
    break;
    case EffectTypes::ColorMaskB:
    {
        color = mRenderTarget.GetColor(x, y);
        color.b = 0.0f;
    }
    break;
    case EffectTypes::Sepia:
    {
        color = mRenderTarget.GetColor(x, y);
        X::Math::Vector3 colorVec = { color.r, color.g, color.b };
        color.r = X::Math::Dot(colorVec, X::Math::Vector3( 0.393f, 0.769f, 0.189f ));
        color.g = X::Math::Dot(colorVec, X::Math::Vector3( 0.349f, 0.686f, 0.168f ));
        color.b = X::Math::Dot(colorVec, X::Math::Vector3( 0.272f, 0.534f, 0.131f ));
    }
    break;
    case EffectTypes::Blur:
    {
        int offset = 4;
        color = mRenderTarget.GetColor(x, y)
            + mRenderTarget.GetColor(x + offset, y)
            + mRenderTarget.GetColor(x - offset, y)
            + mRenderTarget.GetColor(x, y + offset)
            + mRenderTarget.GetColor(x, y - offset)
            + mRenderTarget.GetColor(x + offset, y + offset)
            + mRenderTarget.GetColor(x + offset, y - offset)
            + mRenderTarget.GetColor(x - offset, y + offset)
            + mRenderTarget.GetColor(x - offset, y - offset);
        color /= 9.0f;
    }
    break;
    case EffectTypes::Wave:
    {
        int yRippleLength = 50;
        color = mRenderTarget.GetColor(x, y);
        float ratio = static_cast<float>(y % yRippleLength) / static_cast<float>(yRippleLength - 1);
        float circleValue = (ratio * X::Math::kPi);
        float sinValue = std::sin(circleValue);
        x += static_cast<int>(sinValue * 5.0f);
    }
    break;
    case EffectTypes::FishEye:
    {
        color = mRenderTarget.GetColor(x, y);
        const float effectDistance = 250.0f;
        const float hw = static_cast<float>(mRenderTarget.GetWidth()) * 0.5f;
        const float hh = static_cast<float>(mRenderTarget.GetHeight()) * 0.5f;
        X::Math::Vector2 rangeVac = { hw, hh };
        X::Math::Vector2 distanceVec = { x - hw, y - hh };
        const float rangeDistance = X::Math::Magnitude(rangeVac);
        const float scale = effectDistance / rangeDistance;
        const float distFromCenter = X::Math::Magnitude(distanceVec);
        const float ratio = 1.0f - X::Math::Clamp(distFromCenter / rangeDistance, 0.0f, 1.0f);
        distanceVec = rangeVac + (distanceVec * ratio);
        x = static_cast<int>(distanceVec.x + 0.5f);
        y = static_cast<int>(distanceVec.y + 0.5f);
    }
    break;
    default:
        break;
    }

    X::DrawPixel(x, y, color);
}