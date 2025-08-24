//
// Created by Jose Alberto Barrantes on 23/8/25.
//

#include "../Includes/simulator_core.h"

simulator_core::simulator_core(const int window_width, const int window_height) :
balls(0), window_width(window_width), window_height(window_height) {
  for (int i = 0; i < 10; ++i) {
    ball_list.emplace_back(9*(i+1), 9*(i+1), 9 );
  }
}

unsigned long simulator_core::get_balls() const {
  return balls;
}
std::vector<ball> simulator_core::get_ball_list() const {
  return ball_list;
}

void simulator_core::add_ball() {
  balls++;
}

void simulator_core::add_balls(const unsigned long n) {
  balls += n;
}

void simulator_core::remove_balls(const unsigned long n) {
  if (balls >= n) {
    balls -= n;
  } else {
    balls = 0;
  }
}

void simulator_core::move_Balls() {
  for (auto& ball: ball_list) {
    ball.locX += 15;
    ball.locY += 15;
  }
}

void simulator_core::remove_ball() {
  if (balls > 0) {
    balls--;
  }
}
