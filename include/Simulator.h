#pragma once
#include "raylib.h"
#include <memory>
class Simulator
{
public:

	static void ConfigRaylibWindow();

	static void DrawFrame(std::shared_ptr<Camera3D> cam);

	static void Simulate();

    static std::shared_ptr<Camera3D> GetCam(); 

private:
	static void InitCam();
	static void Draw3dPass(Camera3D* cam);
};

