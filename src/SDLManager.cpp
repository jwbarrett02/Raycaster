#include "SDLManager.hpp"
#include <SDL3/SDL.h>
#include <stdexcept>

static bool sdlInitialized = false;

void InitSDL() {
    if (sdlInitialized)
        return;

    // TODO: Add more flags as SDL functionality is needed.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error(std::string("Failed to initialize SDL: ") + SDL_GetError());
    }

    sdlInitialized = true;
}

void QuitSDL() {
    if (!sdlInitialized)
        return;

    SDL_Quit();
    sdlInitialized = false;
}