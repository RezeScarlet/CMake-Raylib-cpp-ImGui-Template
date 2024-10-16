# CMake Raylib C++ ImGui Template
A template for <a href="https://github.com/raysan5/raylib">Raylib</a>, C++, <a href="https://github.com/ocornut/imgui">ImGui</a>, <a href="https://github.com/raylib-extras/rlImGui">rlImGui</a> and built with Cmake.

## How to Build
Edit CMakeLists.txt and change the project and executable name in lines 2, 9 and 54
```
2   project(PROJECT_NAME)
9   add_executable(PROJECT_NAME src/main.cpp) // or all .cpp files you have on your src/
54  target_link_libraries(PROJECT_NAME PRIVATE imgui rlimgui raylib raylib_cpp)
```
Generate build files and build
```
mkdir build/
cd build/
cmake ..
cmake --build .
```
## How to Run
```
cd build/
./<Project Name (default: raylib-project)>
```
