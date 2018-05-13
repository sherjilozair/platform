#include <string>
#include <window.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <OpenGL/gl3.h>

namespace sys{
  Window::Window(const std::string& title, unsigned int width, unsigned int height): width(width), height(height)
  {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    const char *title_str = title.c_str();
    this->window = SDL_CreateWindow(title_str, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, 0);
    assert(this->window != NULL);
    this->context = SDL_GL_CreateContext(this->window);
    SDL_GL_SetSwapInterval(1);
    
    // this doesn't belong here
    glViewport(0, 0, width, height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  }
  void Window::draw(gfx::Sprite& sprite, gfx::Shader& shader)
  {
    shader.bind();
    sprite.draw();
    shader.unbind();
  }
  bool Window::is_open()
  {
    return !SDL_QuitRequested();
  }

  Window::~Window()
  {
    SDL_DestroyWindow(this->window);
    SDL_GL_DeleteContext(this->context);
    IMG_Quit();
    SDL_Quit();
  }
}