//
// Created by Jose Alberto Barrantes on 23/8/25.
//

#ifndef SIMTEST_BALL_H
#define SIMTEST_BALL_H

class ball {
public:
  ball(int locX, int locY, int radius);
  int locX;
  int locY;
  int radiusSize;
  int vx{}; // velocity x axis.
  int vy{}; // velocity y axis.
};

#endif // SIMTEST_BALL_H
