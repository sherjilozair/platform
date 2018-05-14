#include <string>
#include <OpenGL/gl3.h>
#include <platform.hpp>

int main()
{
  pl::Window window("Retro", 320 * 4, 180 * 4);
  pl::Texture texture("assets/sprites.png");
  pl::Sprite sprite(texture, pl::Rectangle(0, 0, 128, 64));
  pl::Shader shader = pl::Shader::DefaultShader();

  while (window.isOpen())
  {
    window.clear(pl::Color::Black);
    window.draw(sprite, shader);
    window.display();
  }
}