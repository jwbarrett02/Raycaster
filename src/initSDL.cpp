#include "initSDL.hpp"
#include <stdexcept>

static bool sdlInitialized = false;

void initSDL() {
    if (sdlInitialized)
        return;

    // TODO: Add more flags into this statement as SDL functionality is needed.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error(std::string("SDL_Init failed: ") + SDL_GetError());
    }

    sdlInitialized = true;
}

void quitSDL() {
    if (!sdlInitialized)
        return;

    SDL_Quit();
    sdlInitialized = false;
}