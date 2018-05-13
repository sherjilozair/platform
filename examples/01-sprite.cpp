#include <string>
#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds

#include "platform.hpp"
#include <OpenGL/gl3.h>

int main(){
  sys::Window window("Retro", 320 * 4, 180 * 4);
  gfx::Texture texture("assets/sprites.png");
  gfx::Sprite sprite(texture, gfx::Rectangle(0, 0, 64, 64));
  gfx::Shader shader = gfx::Shader::DefaultShader();
  glClearColor(0.0, 0.0, 0.0, 1.0);

  while (window.is_open())
  {
    glClear(GL_COLOR_BUFFER_BIT);
    window.draw(sprite, shader);
    SDL_GL_SwapWindow(window.window);
    //std::cout << glGetString(glGetError()) << std::endl;
  }
}