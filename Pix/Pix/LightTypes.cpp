#include "LightTypes.h"
#include "MaterialManager.h"
#include "Camera.h"

// Directional Light -----------------------------------------------------------------------------
X::Color DirectionalLight::ComputeLightColor(const Vector3& position, const Vector3& normal)
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

// Point Light ----------------------------------------------------------------------------------
X::Color PointLight::ComputeLightColor(const Vector3& position, const Vector3& normal)
{
    Camera* camera = Camera::Get();
    MaterialManager* mm = MaterialManager::Get();

    // Direction to Light
    Vector3 L = mPosition - position;
    float distance = MathHelper::Magnitude(L);
    L /= distance;

    // Calculating iL
    float attenuation = 1.0f / (mAttenConst + (mAttenLinear * distance) + (mAttenQuadratic * distance * distance));
    float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);

    // Calculate Ambient Color
    X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

    // Calculate Diffuse Color
    float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
    X::Color colorDiffuse = mDiffuse * mm->GetMaterialDiffuse() * dot * iL;

    // Calculate Specular Color
    Vector3 v = MathHelper::Normalize(camera->GetPosition() - position);
    Vector3 r = MathHelper::Normalize(L + v);
    float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()), 0.0f);
    X::Color colorSpecular = mSpecular * mm->GetMaterialSpecular() * fallOff * iL;

    return colorAmbient + colorDiffuse + colorSpecular;
}

void PointLight::SetPosition(const Vector3& position)
{
    mPosition = position;
}

void PointLight::SetAttenuation(float constant, float linear, float quadratic)
{
    mAttenConst = constant;
    mAttenLinear = linear;
    mAttenQuadratic = quadratic;
}

// Spot Light -----------------------------------------------------------------------------------
X::Color SpotLight::ComputeLightColor(const Vector3& position, const Vector3& normal)
{
    Camera* camera = Camera::Get();
    MaterialManager* mm = MaterialManager::Get();

    // Direction to Light
    Vector3 L = mPosition - position;
    float distance = MathHelper::Magnitude(L);
    L /= distance;


    // Calculate Ambient Color
    X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

    Vector3 lightDir = -L;
    float dirDot = MathHelper::Dot(lightDir, mDirection);
    if (dirDot < mCosAngle)
    {
        return colorAmbient;
    }

    // Calculating iL
    float spot = pow(dirDot, mDecay);
    float attenuation = spot / (mAttenConst + (mAttenLinear * distance) + (mAttenQuadratic * distance * distance));
    float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);

    // Calculate Diffuse Color
    float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
    X::Color colorDiffuse = mDiffuse * mm->GetMaterialDiffuse() * dot * iL;

    // Calculate Specular Color
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
    mAttenQuadratic = quadratic;
}

void SpotLight::SetAngle(float angle) 
{
    mCosAngle = cos(angle);
}

void SpotLight::SetDecay(float decay)
{
    mDecay = decay;
}