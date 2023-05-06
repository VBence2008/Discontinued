#pragma once

#ifdef _WIN32
#include "X:\Dev\ExCpp\ExCpp.hpp"
#elif __unix__
#endif

class PlayerCamera
{
private:
    Camera2D Camera;

public:
    PlayerCamera()
    {
    }

    ~PlayerCamera()
    {
    }

    void Update()
    {
    }
};