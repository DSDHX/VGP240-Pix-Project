#include "LightManager.h"
#include "MaterialManager.h"

LightManager* LightManager::Get()
{
    static LightManager sInstance;
    return &sInstance;
}

void LightManager::OnNewFrame()
{
    mLights.clear();
    mAmbient = X::Colors::White;
    mDiffuse = X::Colors::White;
    mSpecular = X::Colors::White;
}

void LightManager::SetLightAmbient(const X::Color& color)
{
    mAmbient = color;
}

void LightManager::SetLightDiffuse(const X::Color& color)
{
    mDiffuse = color;
}

void LightManager::SetLightSpecular(const X::Color& color)
{
    mSpecular = color;
}

X::Color LightManager::ComputerLightColor(const Vector3& position, const Vector3& normal) const
{
    X::Color color = MaterialManager::Get()->GetMaterialAmbient();
    for (auto& light : mLights)
    {
        color += light->ComputerLightColor(position, normal);
    }
    return color;
}