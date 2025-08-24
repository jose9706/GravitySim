//
// Created by Jose Alberto Barrantes on 23/8/25.
//

#ifndef SIMTEST_SIMULATOR_GUI_H
#define SIMTEST_SIMULATOR_GUI_H
#include "Utils.h"
#include "simulator_core.h"

class Simulator_gui
{
public:
  Simulator_gui(SDL_Renderer* renderer, SDL_Window* window);
  void UpdateFrame() const;

private:
  void DrawCircle(int32_t centreX, int32_t centreY, int32_t radius) const;
  SDL_Renderer* _renderer;
  SDL_Window* _window;
  std::unique_ptr<simulator_core> simulator;
};

#endif // SIMTEST_SIMULATOR_GUI_H
