#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <shader.hpp>
#include <sprite.hpp>

namespace sys{
  class Window{
    public:
    SDL_Window* window;
    SDL_GLContext context;
    int width, height;
    Window(const std::string&, unsigned int, unsigned int);
    ~Window();
    void draw(gfx::Sprite&, gfx::Shader&);
    bool is_open();
  };
}