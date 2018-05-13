#include <string>
#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds

#include "platform.hpp"
#include <OpenGL/gl3.h>

int main(){
  pl::Window window("Retro", 320 * 4, 180 * 4);
  pl::Texture texture("assets/sprites.png");
  pl::Sprite sprite(texture, pl::Rectangle(0, 0, 64, 64));
  pl::Shader shader = pl::Shader::DefaultShader();
  glClearColor(0.0, 0.0, 0.0, 1.0);

  while (window.is_open())
  {
    glClear(GL_COLOR_BUFFER_BIT);
    window.draw(sprite, shader);
    SDL_GL_SwapWindow(window.window);
    //std::cout << glGetString(glGetError()) << std::endl;
  }
}