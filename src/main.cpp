#include <imgui.h>
#include <raylib.h>
#include <rlImGui.h>
#include <raylib-cpp.hpp>

int main() {

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  raylib::Window window(854, 480);
  SetTargetFPS(60);

  rlImGuiSetup(true);

  while (WindowShouldClose() == false) {

    BeginDrawing();
    rlImGuiBegin();

    ClearBackground(raylib::Color::White());
  
    ImGui::ShowDemoWindow();

    rlImGuiEnd();
    EndDrawing();
  }

  rlImGuiShutdown();

  CloseWindow();
  return 0;
}
