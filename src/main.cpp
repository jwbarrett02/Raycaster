#include "SDLManager.hpp"
#include "GLManager.hpp"
#include <iostream>
#include <glad/glad.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>

int main() {

    std::cout << "Program started...\n";

    initSDL();

    std::cout << "SDL initialized...\n";

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // create an OpenGL compatible window via SDL3
    SDL_Window* window = SDL_CreateWindow(
        "Raycaster",
        800,
        600,
        SDL_WINDOW_OPENGL
    );

    if (!window) {
        std::cerr << "SDL_GL_SDL_CreateWindow failed: " << SDL_GetError() << "\n";
        return 1;
    }

    SDL_ShowWindow(window);

    // create an OpenGL context and associate with window
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);

    if (!gl_context) {
        std::cerr << "SDL_GL_CreateContext failed: " << SDL_GetError() << "\n";
        return 1;
    }

    initGL();

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
        SDL_GL_SwapWindow(window);
    }

    // clean up
    SDL_GL_DestroyContext(gl_context);
    SDL_DestroyWindow(window);
    quitSDL();

    return 0;
}