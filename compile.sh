g++ src/*.cpp examples/01-sprite.cpp -Iinclude -Iexternal/osx/SDL2.framework/Headers -Iexternal/osx/SDL2_image.framework/Headers -Iexternal/glm -Fexternal/osx -framework SDL2 -framework SDL2_image -framework OpenGL -o examples/01-sprite
install_name_tool -add_rpath "@loader_path/../external/osx/" examples/01-sprite