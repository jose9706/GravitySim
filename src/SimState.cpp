#include "SimState.h"
#include "raylib.h"

void SimState::UpdateCursorState()
{
    if (CursorActive)
    {
        DisableCursor();
    }
    else
    {
        EnableCursor();
    }
}

size_t SimState::GetBallCount()
{
    return theBalls.size();
}