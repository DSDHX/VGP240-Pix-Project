#pragma once

#include <XEngine.h>

enum class AddressMode
{
    Border,
    Clamp,
    Wrap,
    Mirror
};

class Texture
{
public:
    void Load(const std::string& filename);
    const std::string& GetFilename() const;

    X::Color GetPixel(float u, float v, bool filter, AddressMode addressMode) const;
    X::Color GetPixel(int u, int v) const;

    int GetWidth() const;
    int GetHeight() const;

private:
    std::string mFileName;
    std::unique_ptr<X::Color[]> mPixels;
    int mWidth = 0;
    int mHeight = 0;
};