cmake_minimum_required(VERSION 3.24)
# project name and version
project(raylib-project)

# C++ minimum version  required
set(CMAKE_CXX_STANDARD 17)
# Let the language server know stuff about the project and libraries
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include the command that downloads libraries
include(FetchContent)

# Glob finds all files in a directory, src/ in this case, and assign to the SRC_FILES variable
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
# Creates the executable with the source files
add_executable(raylib-project ${SRC_FILES})
# Sets the include directory
target_include_directories(raylib-project PRIVATE ${PROJECT_SOURCE_DIR}/include)

# =============== 
# ==== IMGUI ==== 
# =============== 
# Tries to find the library locally and if it doesn't find it, get it from Github
find_package(imgui 1.91.3 QUIET)
if (NOT imgui_FOUND)
  message(STATUS "Getting Dear ImGui from Github")
  FetchContent_Declare(
    ImGui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.91.3
  )
  FetchContent_MakeAvailable(imgui)
  # Add library files
  add_library(
     imgui STATIC
     ${imgui_SOURCE_DIR}/imgui.cpp
     ${imgui_SOURCE_DIR}/imgui_draw.cpp
     ${imgui_SOURCE_DIR}/imgui_demo.cpp
     ${imgui_SOURCE_DIR}/imgui_widgets.cpp
     ${imgui_SOURCE_DIR}/imgui_tables.cpp
  )
  # Set it's include directory
  target_include_directories(imgui INTERFACE ${imgui_SOURCE_DIR})
else()
  message(STATUS "Using Local Dear ImGui library")
endif()

# ================ 
# ==== RAYLIB ==== 
# ================ 
find_package(raylib 5.0 QUIET)
if (NOT raylib_FOUND)
  message(STATUS "Getting raylib from Github")
  FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
  )
  FetchContent_MakeAvailable(raylib)
else()
  message(STATUS "Using Local raylib library")
endif()

# ==================== 
# ==== RAYLIB_CPP ==== 
# ==================== 
find_package(raylib_cpp 5.0.2 QUIET)
if (NOT raylib_cpp_FOUND)
  message(STATUS "Getting raylib-cpp from Github")
  FetchContent_Declare(
    raylib_cpp
    GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
    GIT_TAG v5.0.2
  )
  FetchContent_MakeAvailable(raylib_cpp)
else()
  message(STATUS "Using Local raylib-cpp library")
endif()

# ================= 
# ==== RLIMGUI ==== 
# ================= 
find_package(rlimgui QUIET)
if (NOT rlimgui_FOUND)
  message(STATUS "Getting rlImGui from Github")
  FetchContent_Declare(
     rlImGui
     GIT_REPOSITORY https://github.com/raylib-extras/rlImGui
     # Git Tag can be a release or a commit (like this)
     GIT_TAG c7303258e045b4698c3e0b930b71956b5bbe7dff 
  )
  FetchContent_MakeAvailable(rlImGui)
  # For libraries not compiled with CMake, it's necessary to manually add the source files and set the include directory
  add_library(rlimgui STATIC ${rlimgui_SOURCE_DIR}/rlImGui.cpp)
  target_include_directories(rlimgui INTERFACE ${rlimgui_SOURCE_DIR})
  # Tells the compiler that one library depends on other
  target_link_libraries(rlimgui PRIVATE imgui raylib)
else()
  message(STATUS "Using Local rlimgui library")
endif()


# Link all libraries to the project
target_link_libraries(raylib-project PRIVATE imgui rlimgui raylib raylib_cpp)
