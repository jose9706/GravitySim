#pragma once
#include "raylib.h"
#include "SimState.h"
#include <memory>
#include <string>

class Simulator
{
public:

    static void ConfigRaylibWindow();
    static void DrawFrame(std::shared_ptr<Camera3D> cam, const SimState& state);
    static void Simulate();
    static std::shared_ptr<Camera3D> GetCam();
    static std::string GetBallsOnScreenText(int numBalls);
    static void ShowMenu();
    static void HandleKeyBoard(SimState& simState);

private:
    static void InitCam();
    static void Draw3dPass(Camera3D* cam);
};