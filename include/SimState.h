#pragma once
#include "raylib.h"
#include <stdio.h>
#include <vector>
#include "Ball.h"

#define CURSOR_DISABLING_KEY KEY_F1
#define MAX_BALLS 1000
class SimState
{
public:
    void UpdateCursorState();
    void SpawnBall();
    void RemoveBall();
    size_t GetBallCount();
private:
    bool CursorActive = false;
    Camera3D origCam;
    std::vector<Ball> theBalls; 
};