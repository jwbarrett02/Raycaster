#include "GLManager.hpp"
#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <stdexcept>

void initGL() {
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        throw std::runtime_error(std::string("gladLoadGLLoader failed: ") + SDL_GetError());
    }
}