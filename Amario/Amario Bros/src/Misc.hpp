#pragma once

#ifdef _WIN32
#include "X:\Dev\ExCpp\ExCpp.hpp"
#elif __linux__
#endif

Texture2D TextureFlip(Texture2D Texture)
{
    Image Image = LoadImageFromTexture(Texture);
    ImageFlipHorizontal(&Image);
    Texture2D TextureNew = LoadTextureFromImage(Image);
    UnloadImage(Image);
    return TextureNew;
}