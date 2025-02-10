#include "MatrixStack.h"

MatrixStack* MatrixStack::Get()
{
	static MatrixStack sInstance;
	return &sInstance;
}

void MatrixStack::OnNewFrame()
{
	mCombinedTransform = Matrix4::Identity();
	mMatrices.clear();
}

void MatrixStack::PushTranslation(const Vector3& d)
{
	Matrix4 translationMatrix = Matrix4::Translation(d);
	mMatrices.push_back(translationMatrix);
	mCombinedTransform = translationMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationX(float rad)
{
	Matrix4 rotationMatrix = Matrix4::RotationX(rad);
	mMatrices.push_back(rotationMatrix);
	mCombinedTransform = rotationMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationY(float rad)
{
	Matrix4 rotationMatrix = Matrix4::RotationY(rad);
	mMatrices.push_back(rotationMatrix);
	mCombinedTransform = rotationMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationZ(float rad)
{
	Matrix4 rotationMatrix = Matrix4::RotationZ(rad);
	mMatrices.push_back(rotationMatrix);
	mCombinedTransform = rotationMatrix * mCombinedTransform;
}

void MatrixStack::PushScaling(const Vector3& s)
{
	Matrix4 scalingMatrix = Matrix4::Scale(s);
	mMatrices.push_back(scalingMatrix);
	mCombinedTransform = scalingMatrix * mCombinedTransform;
}

void MatrixStack::PopMatrix()
{
	if (!mMatrices.empty())
	{
		Matrix4 matrix = mMatrices.back();
		mMatrices.pop_back();
		mCombinedTransform = MathHelper::Inverse(matrix) * mCombinedTransform;
	}
}

const Matrix4& MatrixStack::GetTransform() const
{
	return mCombinedTransform;
}
