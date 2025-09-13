#pragma once
#include <stdlib.h>

typedef struct Ball
{
    size_t x;
    size_t y;
    size_t velocity;
    size_t accel;
} Ball, *pBall;