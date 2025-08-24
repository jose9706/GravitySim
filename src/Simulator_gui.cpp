//
// Created by Jose Alberto Barrantes on 23/8/25.
//

#include "../Includes/Simulator_gui.h"
Simulator_gui::Simulator_gui(SDL_Renderer* renderer,
SDL_Window* window)
    : _renderer(renderer), _window(window) {
  int w, h;
  SDL_GetWindowSize(_window, &w, &h);
  simulator = std::make_unique<simulator_core>(w, h);
}

void Simulator_gui::UpdateFrame() const {
  SDL_SetRenderDrawColor(_renderer, 0,0,0, 255);
  SDL_RenderClear(_renderer);
  for (const auto ball : simulator->get_ball_list()) {
    {
      DrawCircle(ball.locX, ball.locY, ball.radiusSize);
    }
  }
  SDL_RenderPresent(_renderer);
}

  void Simulator_gui::DrawCircle(int32_t centreX, int32_t centreY, int32_t radius) const
  {
    SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
    if (SDL_SetRenderDrawColor(_renderer, GREEN, 150) != 0)
    {
    }
    SDL_FPoint points[1300]; // Maybe use vectors here ?? but we allocate to stack anyways ig.
    int count = 0;
    for (int y = -radius; y <= radius; y++)
    {
      for (int x = -radius; x <= radius; x++)
      {
        if (x * x + y * y <= radius * radius)
        { // Check if point is within the circle
          SDL_FPoint point;
          point.x = centreX + x;
          point.y = centreY + y;
          points[count] = point;
          count++;
        }
      }
    }

    SDL_RenderPoints(_renderer, points, count); // Supposed to be faster to just call this once.. ?
  }