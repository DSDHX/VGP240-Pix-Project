#include "CmdVertex.h"
#include "PrimitiveManager.h"

bool CmdVertex::Execute(const std::vector<std::string>& params)
{
	float x, y, z = 0.0f;
	float r, g, b = 1.0f;
	if (params.size() == 2)
	{
		x = std::stof(params[0]);
		y = std::stof(params[1]);
	}
	else if (params.size() == 3)
	{
		x = std::stof(params[0]);
		y = std::stof(params[1]);
		z = std::stof(params[2]);
	}
	else if (params.size() == 5)
	{
		x = std::stof(params[0]);
		y = std::stof(params[1]);
		r = std::stof(params[2]);
		g = std::stof(params[3]);
		b = std::stof(params[4]);
	}
	else if (params.size() == 6)
	{
		x = std::stof(params[0]);
		y = std::stof(params[1]);
		z = std::stof(params[2]);
		r = std::stof(params[3]);
		g = std::stof(params[4]);
		b = std::stof(params[5]);
	}
	else { return false; }

	Vertex v;
	v.pos = { x, y, z };
	v.color = { r, g, b, 1.0f };
	PrimitiveManager::Get()->AddVertex(v);
	return true;
}