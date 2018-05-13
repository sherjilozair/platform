#include "shader.hpp"
#include <OpenGL/gl3.h>

#define CODE(...) #__VA_ARGS__

namespace gfx{

  Shader::Shader(const std::string& vs_code, const std::string& fs_code){
    unsigned int _vs_id = glCreateShader(GL_VERTEX_SHADER);
    const char* vs_code_c_str = vs_code.c_str();
    glShaderSource(_vs_id, 1, &vs_code_c_str, NULL);
    glCompileShader(_vs_id);

    int success;
    char infolog[512];
    glGetShaderiv(_vs_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      glGetShaderInfoLog(_vs_id, 512, NULL, infolog);
      printf("%s\n", infolog);
    }

    // fragment shader
    unsigned int _fs_id = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fs_code_c_str = fs_code.c_str();
    glShaderSource(_fs_id, 1, &fs_code_c_str, NULL);
    glCompileShader(_fs_id);

    glGetShaderiv(_fs_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      glGetShaderInfoLog(_fs_id, 512, NULL, infolog);
      printf("%s\n", infolog);
    }

    // create program
    this->_id = glCreateProgram();
    glAttachShader(this->_id, _vs_id);
    glAttachShader(this->_id, _fs_id);
    glLinkProgram(this->_id);

    glGetProgramiv(this->_id, GL_LINK_STATUS, &success);

    if (!success)
    {
      glGetProgramInfoLog(this->_id, 512, NULL, infolog);
      printf("%s\n", infolog);
    }
  }

  void Shader::bind(){
    glUseProgram(this->_id);
  }
  void Shader::unbind(){
    glUseProgram(0);
  }

  Shader Shader::DefaultShader()
  {
    std::string vs_code = "#version 330 core\n" CODE(
        layout(location = 0) in vec2 position;
        layout(location = 1) in vec2 texcoord;

        out vec2 ftexcoord;

        void main() {
          gl_Position = vec4(position, 0.0, 1.0);
          ftexcoord = texcoord;
        });

    // fragment shader
    std::string fs_code = "#version 330 core\n" CODE(
        out vec4 pcolor;
        in vec2 ftexcoord;
        uniform sampler2D tex;

        void main() {
          pcolor = texture(tex, ftexcoord);
        }
      );

    return Shader(vs_code, fs_code);
  }
}