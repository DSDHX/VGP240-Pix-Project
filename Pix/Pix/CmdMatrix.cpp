#include "CmdMatrix.h"
#include "MatrixStack.h"
#include "VariableCache.h"

bool CmdPushTranslation::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float x = vc->GetFloat(params[0]);
	float y = vc->GetFloat(params[1]);
	float z = vc->GetFloat(params[2]);
	MatrixStack::Get()->PushTranslation({x, y, z});
	return true;
}

bool CmdPushRotationX::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float degree = vc->GetFloat(params[0]);
	MatrixStack::Get()->PushRotationX(degree * MathHelper::DegToRad);
	return true;
}

bool CmdPushRotationY::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float degree = vc->GetFloat(params[0]);
	MatrixStack::Get()->PushRotationY(degree * MathHelper::DegToRad);
	return true;
}

bool CmdPushRotationZ::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float degree = vc->GetFloat(params[0]);
	MatrixStack::Get()->PushRotationZ(degree * MathHelper::DegToRad);
	return true;
}

bool CmdPushScaling::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float x = vc->GetFloat(params[0]);
	float y = vc->GetFloat(params[1]);
	float z = vc->GetFloat(params[2]);
	MatrixStack::Get()->PushScaling({ x, y, z });
	return true;
}

bool CmdPopMatrix::Execute(const std::vector<std::string>& params)
{
	MatrixStack::Get()->PopMatrix();
	return true;
}
