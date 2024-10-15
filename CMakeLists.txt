cmake_minimum_required(VERSION 3.24)
project(raylib-project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

add_executable(raylib-project src/main.cpp)

FetchContent_Declare(
   ImGui
   GIT_REPOSITORY https://github.com/ocornut/imgui.git
   GIT_TAG v1.91.3
)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.0
)

FetchContent_Declare(
   raylib_cpp
   GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
   GIT_TAG v5.0.2
)
FetchContent_Declare(
   rlImGui
   GIT_REPOSITORY https://github.com/raylib-extras/rlImGui
   GIT_TAG c7303258e045b4698c3e0b930b71956b5bbe7dff 
)

FetchContent_MakeAvailable(imgui raylib raylib_cpp rlImGui)

FetchContent_GetProperties(raylib_cpp SOURCE_DIR RAYLIB_CPP_DIR)
# add_library(raylib_cpp STATIC ${raylib_cpp_SOURCE_DIR}/include/raylib_cpp.hpp)

# FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)
add_library(
   imgui STATIC
   ${imgui_SOURCE_DIR}/imgui.cpp
   ${imgui_SOURCE_DIR}/imgui_draw.cpp
   ${imgui_SOURCE_DIR}/imgui_demo.cpp
   ${imgui_SOURCE_DIR}/imgui_widgets.cpp
   ${imgui_SOURCE_DIR}/imgui_tables.cpp
)
target_include_directories(imgui INTERFACE ${imgui_SOURCE_DIR})

# FetchContent_GetProperties(rlImGui SOURCE_DIR RLIMGUI_DIR)
add_library(rlimgui STATIC ${rlimgui_SOURCE_DIR}/rlImGui.cpp)
target_link_libraries(rlimgui PRIVATE imgui raylib)
target_include_directories(rlimgui INTERFACE ${rlimgui_SOURCE_DIR})

target_link_libraries(raylib-project PRIVATE imgui rlimgui raylib raylib_cpp)
