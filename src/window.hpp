#ifndef WINDOW_HPP
#define WINDOW_HPP
#pragma once
#include <SDL3/SDL.h>

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();

    void SwapBuffers();

    SDL_Window* GetSDLWindow() const { return m_window; }
    SDL_GLContext GetGLContext() const { return m_glContext; }

private:
    bool CreateWindow(const char* title, int width, int height);
    bool CreateGLContext();

    SDL_Window* m_window = nullptr;
    SDL_GLContext m_glContext = nullptr;
};

#endif