#pragma once
#include <string>

namespace gfx{
  class Shader{
    public:
    unsigned int _id;
    Shader(const std::string&, const std::string&);
    void bind();
    void unbind();
    static Shader DefaultShader();
  };
}