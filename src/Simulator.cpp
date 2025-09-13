
#include "Simulator.h"
#include "raylib.h"
#include <cstddef>
#include <cstdio>
#include <memory>
#include <string>


std::shared_ptr<Camera3D> Simulator::GetCam() {
    auto cam = std::make_shared<Camera3D>();
    cam->position = { 0.0f, 10.0f, 10.0f };
    cam->target = { 0.0f, 0.0f, 0.0f };
    cam->up = { 0.0f, 1.0f, 0.0f };
    cam->fovy = 45.0f;
    cam->projection = CAMERA_PERSPECTIVE;
    return cam; 
}

void Simulator::Draw3dPass(Camera3D* cam)
{
    if (cam == nullptr)
    {
        fprintf(stderr, "The camera is null and that is not really expected. Not Crashing tho!");
        return;
    }

    UpdateCamera(cam, CAMERA_THIRD_PERSON);
    BeginMode3D(*cam);

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

    DrawGrid(20, 1.0f);        // Draw a grid

    EndMode3D();
}

void Simulator::ConfigRaylibWindow()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(1280, 800, "Grav simulatro");
    SetTargetFPS(60);
    DisableCursor();
}

void Simulator::DrawFrame(std::shared_ptr<Camera3D> cam)
{
    BeginDrawing();
    DrawFPS(100, 10);
    ClearBackground(BLACK);
    DrawText(GetBallsOnScreenText(0).c_str(), 100, 30, 20, WHITE);
    DrawText("Press M for menu", 100, 60, 15, WHITE);
    EndDrawing();
}

std::string Simulator::GetBallsOnScreenText(int numBalls)
{
    return "Balls on screen: " + std::to_string(numBalls);
}

void Simulator::Simulate()
{
    auto cam = GetCam();
    auto state = SimState();
    while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
    {
        DrawFrame(cam);
    }

    // destroy the window and cleanup the OpenGL context
    CloseWindow();
}

void Simulator::HandleKeyBoard()
{
    auto state = SimState();
    if (IsKeyPressed(CURSOR_DISABLING_KEY))
    {
        state.UpdateCursorState();  
    }
}

