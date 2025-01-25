#pragma once

#include "Vertex.h"

class Clipper
{
public:
	static Clipper* Get();

	void OnNewFrame();

	bool ClipPoint(const Vertex& v);
	bool ClipLine(Vertex& a, Vertex& b);
	bool ClipTriangle(std::vector<Vertex>& vertices);

	bool IsClipping() const;
	void SetClipping(bool clip);

private:
	bool mClipping = false;
};