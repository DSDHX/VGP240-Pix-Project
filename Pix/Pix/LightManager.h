#pragma once

#include <XEngine.h>
#include "Light.h"

class LightManager
{
public:
	static LightManager* Get();

	void OnNewFrame();

	void SetLightAmbient(const X::Color& color);
	void SetLightDiffuse(const X::Color& color);
	void SetLightSpecular(const X::Color& color);

	X::Color ComputerLightColor(const Vector3& position, const Vector3& normal) const;

private:
	std::vector<std::unique_ptr<Light>> mLights;
	X::Color mAmbient = X::Colors::White;
	X::Color mDiffuse = X::Colors::White;
	X::Color mSpecular = X::Colors::White;
};