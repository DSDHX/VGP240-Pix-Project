#pragma once

#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

enum class CullMode
{
	None,
	Back,
	Front
};

class PrimitiveManager
{
public:
	static PrimitiveManager* Get();

	void OnNewFrame();
	void SetCullMode(CullMode mode);
	void SetCorrectUV(bool correctUV);

	bool BeginDraw(Topology topology, bool applyTransform = false);
	void AddVertex(const Vertex& vertex);
	bool EndDraw();

private:
	PrimitiveManager();

	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Point;
	CullMode mCullMode = CullMode::Back;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
    bool mCorrectUV = false;
};