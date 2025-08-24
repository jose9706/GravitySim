//
// Created by Jose Alberto Barrantes on 23/8/25.
//

#ifndef SIMTEST_SIMULATOR_CORE_H
#define SIMTEST_SIMULATOR_CORE_H
#include "ball.h"

#include <vector>

class simulator_core {
public:
  simulator_core(int window_width, int window_height);
  [[nodiscard]] unsigned long get_balls() const;
  [[nodiscard]] std::vector<ball> get_ball_list() const;
  void add_ball();
  void add_balls(unsigned long n);
  void remove_ball();
  void remove_balls(unsigned long n);
  void move_Balls();
private:
  unsigned long balls;
  std::vector<ball> ball_list;
  int window_width;
  int window_height;
};

#endif // SIMTEST_SIMULATOR_CORE_H
