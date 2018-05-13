#pragma once
#include "texture.hpp"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/constants.hpp> // glm::pi

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
    glm::mat4 model;
    
    void draw();
    Sprite(const Texture &, Rectangle);
  };
}