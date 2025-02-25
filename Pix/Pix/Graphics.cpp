#include "Graphics.h"

#include "Viewport.h"
#include "Clipper.h"
#include "MatrixStack.h"
#include "Camera.h"
#include "PrimitiveManager.h"
#include "DepthBuffer.h"
#include "MaterialManager.h"

void Graphics::NewFrame()
{
	Viewport::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	MatrixStack::Get()->OnNewFrame();
	Camera::Get()->OnNewFrame();
	PrimitiveManager::Get()->OnNewFrame();
	DepthBuffer::Get()->OnNewFrame();
	MaterialManager::Get()->OnNewFrame();
}