#pragma once

#include <cstdint>
#include <string>

#include <imgui.h>

namespace Ship {

class Mobile {
  public:
    static void ImGuiProcessEvent(bool wantsTextInput);
    // Touchscreen camera controls for Android
    static bool IsUsingTouchscreenControls();
    static float GetCameraYaw();
    static float GetCameraPitch();
    static void SetCameraYaw(float yaw);
    static void SetCameraPitch(float pitch);
};
}; // namespace Ship
