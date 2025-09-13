#pragma once
#include "raylib.h"
#include "SimState.h"
#include <memory>
class Simulator
{
public:

    static void ConfigRaylibWindow();
    static void DrawFrame(std::shared_ptr<Camera3D> cam);
    static void Simulate();
    static std::shared_ptr<Camera3D> GetCam();
    static std::string GetBallsOnScreenText(int numBalls);
    void ShowMenu();
    void HandleKeyBoard();

private:
    static void InitCam();
    static void Draw3dPass(Camera3D* cam);
};