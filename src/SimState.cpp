#include "SimState.h"

void SimState::KeyBoardKeys()
{
    if (IsKeyDown(KEY_F1)) 
    {
        if (CursorActive)
        {
            DisableCursor();
        }
        else
        {
            EnableCursor();
        }
        
        CursorActive = !CursorActive;
    }
}