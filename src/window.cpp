#include "window.hpp"
#include <glad/glad.h>
#include <stdexcept>

Window::Window(const char* title, int width, int height) {
    if (!CreateWindow(title, width, height))
        return;

    if (!CreateGLContext())
        return;
}

Window::~Window() {
    if (m_glContext) {
        SDL_GL_DestroyContext(m_glContext);
        m_glContext = nullptr;
    }

    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
}

bool Window::CreateWindow(const char* title, int width, int height) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    // TODO: Add more flags for window creation when implementing user settings.
    m_window = SDL_CreateWindow(title, width, height, SDL_WINDOW_OPENGL);

    if (!m_window) {
        throw std::runtime_error(std::string("Failed to create SDL window: ") + SDL_GetError());
        return false;
    }

    return true;
}

bool Window::CreateGLContext() {
    m_glContext = SDL_GL_CreateContext(m_window);

    if (!m_glContext) {
        throw std::runtime_error(std::string("Failed to create OpenGL context: ") + SDL_GetError());
        return false;
    }

    if (SDL_GL_MakeCurrent(m_window, m_glContext) < 0) {
        throw std::runtime_error(std::string("Failed to make GL context current: ") + SDL_GetError());
        return false;
    }

    return true;
}

void Window::SwapBuffers() {
    SDL_GL_SwapWindow(m_window);
}