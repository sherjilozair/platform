#pragma once
#include "texture.hpp"
#include <string>

namespace gfx{
  class Texture{
    public:
    unsigned int width, height, n_channels;
    unsigned int _id;
    Texture(const std::string&);
    void bind() const;
    void unbind() const;
  };
}