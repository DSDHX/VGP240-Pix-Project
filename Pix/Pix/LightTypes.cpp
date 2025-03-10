#include "LightTypes.h"
#include "MaterialManager.h"
#include "Camera.h"

X::Color DirectionalLight::ComputerLightColor(const Vector3& position, const Vector3& normal)
{
    Camera* camera = Camera::Get();
    MaterialManager* mm = MaterialManager::Get();

    X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

    Vector3 L = -mDirection;
    float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
    X::Color colorDiffuse = mDiffuse * mm->GetMaterialDiffuse() * dot;

    Vector3 v = MathHelper::Normalize(camera->GetPosition() - position);
    Vector3 r = MathHelper::Normalize(L + v);
    float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()), 0.0f);
    X::Color colorSpecular = mSpecular * mm->GetMaterialSpecular() * fallOff;

    return colorAmbient + colorDiffuse + colorSpecular;
}

void DirectionalLight::SetDirection(const Vector3& direction)
{
    mDirection = MathHelper::Normalize(direction);
}

X::Color PointLight::ComputerLightColor(const Vector3& position, const Vector3& normal)
{
    Camera* camera = Camera::Get();
    MaterialManager* mm = MaterialManager::Get();

    Vector3 L = mPosition - position;
    float distance = MathHelper::Magnitude(L);
    L /= distance;

    float attenuation = 1.0f / (mAttenConst + (mAttenLinear * distance) + (mAttenQuad * distance * distance));
    float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);

    X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

    float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
    X::Color colorDiffuse = mDiffuse * mm->GetMaterialDiffuse() * dot * iL;

    Vector3 v = MathHelper::Normalize(camera->GetPosition() - position);
    Vector3 r = MathHelper::Normalize(L + v);
    float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()), 0.0f);
    X::Color colorSpecular = mSpecular * mm->GetMaterialSpecular() * fallOff * iL;

    return colorAmbient + colorDiffuse + colorSpecular;
}

void PointLight::SetPosition(const Vector3& position)
{
}

void PointLight::SetAttenuation(float constant, float linear, float quadratic)
{
}

X::Color SpotLight::ComputerLightColor(const Vector3& position, const Vector3& normal)
{
    Camera* camera = Camera::Get();
    MaterialManager* mm = MaterialManager::Get();

    Vector3 L = mPosition - position;
    float distance = MathHelper::Magnitude(L);
    L /= distance;

    X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

    Vector3 lightDir = -L;
    float dirDot = MathHelper::Dot(lightDir, mDirection);
    if (dirDot < mCosAngle)
    {
        return colorAmbient;
    }

    float spot = pow(dirDot, mDecay);
    float attenuation = spot / (mAttenConst + (mAttenLinear * distance) + (mAttenQuad * distance * distance));
    float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);

    float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
    X::Color colorDiffuse = mDiffuse * mm->GetMaterialDiffuse() * dot * iL;

    Vector3 v = MathHelper::Normalize(camera->GetPosition() - position);
    Vector3 r = MathHelper::Normalize(L + v);
    float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()), 0.0f);
    X::Color colorSpecular = mSpecular * mm->GetMaterialSpecular() * fallOff * iL;

    return colorAmbient + colorDiffuse + colorSpecular;
}

void SpotLight::SetPosition(const Vector3& position)
{
    mPosition = position;
}

void SpotLight::SetDirection(const Vector3& direction)
{
    mDirection = direction;
}

void SpotLight::SetAttenuation(float constant, float linear, float quadratic)
{
    mAttenConst = constant;
    mAttenLinear = linear;
    mAttenQuad = quadratic;
}

void SpotLight::SetAngle(float angle)
{
    mCosAngle = cos(angle);
}

void SpotLight::SetDecay(float decay)
{
    mDecay = decay;
}