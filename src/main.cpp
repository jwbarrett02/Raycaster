#include "SDLManager.hpp"
#include "GLManager.hpp"
#include "window.hpp"
#include <iostream>
#include <glad/glad.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>

int main() {

    InitSDL();
    Window window("Raycaster", 1280, 720);
    InitGL();

    // main loop
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        glClearColor(0.1, 0.2, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        window.SwapBuffers();
    }

    // clean up
    window.~Window();
    QuitSDL();

    return 0;
}