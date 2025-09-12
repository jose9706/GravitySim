#pragma once
#include "raylib.h"

class SimState
{
public:
    void KeyBoardKeys();

private:
    bool CursorActive = false;
    Camera3D origCam;
};