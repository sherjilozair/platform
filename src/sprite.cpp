#include "texture.hpp"
#include "sprite.hpp"
#include <OpenGL/gl3.h>

namespace gfx
{
  Rectangle::Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}


  Sprite::Sprite(const Texture &texture, Rectangle src):texture(texture)
  {
    float vertices[] = {
        // positions                                  // texture coords
        1.0, 1.0,                       ((float)src.x + src.w) / texture.width, 1.0 - ((float)src.y + src.h) / texture.height,
        1.0, -1.0,                      ((float)src.x + src.w) / texture.width, 1 - ((float)src.y) / texture.height,
        -1.0, -1.0,                     ((float)src.x) / texture.width, 1 - ((float)src.y) / texture.height,
        -1.0, 1.0,                      ((float)src.x) / texture.width, 1 - ((float)src.y + src.h) / texture.height
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    unsigned int VBO, EBO;
    glGenVertexArrays(1, &this->_id);

    glBindVertexArray(this->_id);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindTexture(GL_TEXTURE_2D, texture._id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  }

  void Sprite::draw(){
    this->texture.bind();
    glBindVertexArray(this->_id);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  }

} // namespace gfx