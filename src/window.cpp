#include <string>
#include <window.hpp>
#include <OpenGL/gl3.h>
#include <color.hpp>

namespace pl
{
Window::Window(const std::string &title, unsigned int width, unsigned int height) : width(width), height(height)
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
void Window::draw(pl::Sprite &sprite, pl::Shader &shader)
{
  shader.bind();
  sprite.draw();
  shader.unbind();
}
bool Window::isOpen()
{
  return !SDL_QuitRequested();
}

void Window::display()
{
  SDL_GL_SwapWindow(this->window);
}

void Window::clear(const Color &color)
{
  glClearColor(color.r / 255.f, color.g / 255.f, color.b / 255.f, color.a / 255.f);
  glClear(GL_COLOR_BUFFER_BIT);
}

Window::~Window()
{
  SDL_DestroyWindow(this->window);
  SDL_GL_DeleteContext(this->context);
  IMG_Quit();
  SDL_Quit();
}
} // namespace pl