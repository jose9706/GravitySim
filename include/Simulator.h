#pragma once
#include "raylib.h"

class Simulator
{
public:
	Simulator();
	~Simulator() = default;

	void ConfigRaylibWindow();

	static void DrawFrame();

	void Simulate();

private:
	Camera3D cam;
	void InitCam();
	static void Draw3dPass(Camera3D cam);
};

