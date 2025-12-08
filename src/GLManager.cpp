#include "GLManager.hpp"
#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <stdexcept>

void InitGL() {
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        throw std::runtime_error(std::string("Failed to initialize glad: ") + SDL_GetError());
    }
}