
#include "Simulator.h"

Simulator::Simulator()
{
	InitCam();
}

void Simulator::InitCam()
{
	cam = { 0 };
	cam.position = { 0.0f, 10.0f, 10.0f };
	cam.target = { 0.0f, 0.0f, 0.0f };
	cam.up = { 0.0f, 1.0f, 0.0f };
	cam.fovy = 45.0f;
	cam.projection = CAMERA_PERSPECTIVE;
}

void Simulator::Draw3dPass(Camera3D cam)
{
	UpdateCamera(&cam, CAMERA_THIRD_PERSON);
	BeginMode3D(cam);

	DrawCube({ -4.0f, 0.0f, 2.0f }, 2.0f, 5.0f, 2.0f, RED);
	DrawCubeWires({ -4.0f, 0.0f, 2.0f }, 2.0f, 5.0f, 2.0f, GOLD);
	DrawCubeWires({ -4.0f, 0.0f, -2.0f }, 3.0f, 6.0f, 2.0f, MAROON);

	DrawSphere({ -1.0f, 0.0f, -2.0f }, 1.0f, GREEN);
	DrawSphereWires({ 1.0f, 0.0f, 2.0f }, 2.0f, 16, 16, LIME);

	DrawCylinder({ 4.0f, 0.0f, -2.0f }, 1.0f, 2.0f, 3.0f, 4, SKYBLUE);
	DrawCylinderWires({ 4.0f, 0.0f, -2.0f }, 1.0f, 2.0f, 3.0f, 4, DARKBLUE);
	DrawCylinderWires({ 4.5f, -1.0f, 2.0f }, 1.0f, 1.0f, 2.0f, 6, BROWN);

	DrawCylinder({ 1.0f, 0.0f, -4.0f }, 0.0f, 1.5f, 3.0f, 8, GOLD);
	DrawCylinderWires({ 1.0f, 0.0f, -4.0f }, 0.0f, 1.5f, 3.0f, 8, PINK);

	DrawCapsule({ -3.0f, 1.5f, -4.0f }, { -4.0f, -1.0f, -4.0f }, 1.2f, 8, 8, VIOLET);
	DrawCapsuleWires({ -3.0f, 1.5f, -4.0f }, { -4.0f, -1.0f, -4.0f }, 1.2f, 8, 8, PURPLE);

	DrawGrid(10, 1.0f);        // Draw a grid

	EndMode3D();
}

void Simulator::ConfigRaylibWindow()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);
	InitWindow(1280, 800, "Grav simulatro");
	SetTargetFPS(60);
	DisableCursor();
}

void Simulator::DrawFrame()
{
	// drawing
	BeginDrawing();

	// Setup the back buffer for drawing (clear color and depth buffers)
	ClearBackground(BLACK);
	Draw3dPass();
	// draw some text using the default font
	DrawText("Hello Raylib", 200, 200, 20, WHITE);
	// end the frame and get ready for the next one  (display frame, poll input, etc...)
	EndDrawing();
}

void Simulator::Simulate()
{
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		DrawFrame();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
}


