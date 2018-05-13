#include "texture.hpp"
#include <SDL_image.h>
#include <OpenGL/gl3.h>
#include <iostream>

namespace gfx{
  Texture::Texture(const std::string& path){
    SDL_Surface *tex = IMG_Load(path.c_str());
    this->width = tex->w;
    this->height = tex->h;
    this->n_channels = tex->format->BytesPerPixel;
    std::cout << "loaded texture " << this->width << " " << this->height << " " << this->n_channels << std::endl;
    glGenTextures(1, &this->_id);
    glBindTexture(GL_TEXTURE_2D, this->_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    const GLint srcformat = tex->format->BytesPerPixel == 3? GL_RGB: GL_RGBA;
    const GLint dstformat = tex->format->BytesPerPixel == 3? GL_RGB: GL_RGBA;
    glTexImage2D(GL_TEXTURE_2D, 0, dstformat, tex->w, tex->h, 0, srcformat, GL_UNSIGNED_BYTE, tex->pixels);
    SDL_FreeSurface(tex);
    glBindTexture(GL_TEXTURE_2D, 0);
  }

  void Texture::bind() const{
    glBindTexture(GL_TEXTURE_2D, this->_id);
  }
  void Texture::unbind() const{
    glBindTexture(GL_TEXTURE_2D, 0);
  }
}