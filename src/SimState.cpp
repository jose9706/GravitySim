#include "SimState.h"
#include "raylib.h"

void SimState::UpdateCursorState()
{
    if (!CursorActive)
    {
        EnableCursor();
        SetMousePosition(MousePosWhenHidden.x, MousePosWhenHidden.y);
    }
    else
    {
        MousePosWhenHidden = GetMousePosition();
        DisableCursor();
    }

    CursorActive = !CursorActive;   
}

void SimState::UpdateMenuState()
{
    MenuOpen = !MenuOpen;
}

size_t SimState::GetBallCount()
{
    return theBalls.size();
}

bool SimState::GetMenuOpen() const
{
    return MenuOpen;
}
