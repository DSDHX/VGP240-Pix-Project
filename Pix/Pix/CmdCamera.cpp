#include "CmdCamera.h"
#include "Camera.h"
#include "VariableCache.h"

bool CmdSetCameraPosition::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float x = vc->GetFloat(params[0]);
	float y = vc->GetFloat(params[1]);
	float z = vc->GetFloat(params[2]);
	Camera::Get()->SetPosition({ x, y, z });
	return true;
}

bool CmdSetCameraDirection::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float x = vc->GetFloat(params[0]);
	float y = vc->GetFloat(params[1]);
	float z = vc->GetFloat(params[2]);
	Camera::Get()->SetDirection({ x, y, z });
	return true;
}

bool CmdSetCameraNear::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float value = vc->GetFloat(params[0]);
	Camera::Get()->SetNearPlane(value);
	return true;
}

bool CmdSetCameraFar::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float value = vc->GetFloat(params[0]);
	Camera::Get()->SetFarPlane(value);
	return true;
}

bool CmdSetCameraFov::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float degrees = vc->GetFloat(params[0]);
	Camera::Get()->SetFOV(degrees * MathHelper::DegToRad);
	return true;
}
