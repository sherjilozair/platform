#pragma once
#include "texture.hpp"

namespace gfx{
  class Rectangle
  {
    public:
    int x, y, w, h;
    Rectangle(int x, int y, int w, int h);
  };

  class Sprite
  {
    public:
    unsigned int _id;
    const Texture& texture;
    void draw();
    Sprite(const Texture &, Rectangle);
  };
}