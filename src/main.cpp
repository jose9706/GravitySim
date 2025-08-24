
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "../Includes/Simulator_gui.h"

static std::unique_ptr<Simulator_gui> simulator;


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) == false)
    {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Couldn't initialize SDL!",
                             SDL_GetError(), nullptr);
    return SDL_APP_FAILURE;
  }

  SDL_Window *window;
  SDL_Renderer *renderer;
  // 800x450 is 16:9
  if (SDL_CreateWindowAndRenderer("Some simulation thing", 800, 450, SDL_WINDOW_OPENGL, &window,
                                  &renderer) == false) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                             "Couldn't create window/renderer!", SDL_GetError(),
                             nullptr);
    return SDL_APP_FAILURE;
  }

  simulator = std::make_unique<Simulator_gui>(renderer, window);
  // return success!
  return SDL_APP_CONTINUE;
}

// This function runs when a new event occurs
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
  switch (event->type) {
  case SDL_EVENT_QUIT:
    // end the program, reporting success to the OS
    return SDL_APP_SUCCESS;
  case SDL_EVENT_KEY_DOWN:
    if (event->key.key == SDLK_ESCAPE) {
      // end the program on ESC key,
      // returning success to the OS
      return SDL_APP_SUCCESS;
    }
  default:
    break;
  }

  // return continue to continue
  return SDL_APP_CONTINUE;
}

// This function runs once per frame, and is the heart of the program
SDL_AppResult SDL_AppIterate(void *appstate) {
  simulator->UpdateFrame();
  // return continue to continue
  return SDL_APP_CONTINUE;
}

// This function runs once at shutdown
void SDL_AppQuit(void *appstate, SDL_AppResult result) {
  // SDL will clean up the window/renderer for us.
}