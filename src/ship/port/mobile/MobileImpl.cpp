#if defined(__ANDROID__) || defined(__IOS__)
#include "ship/port/mobile/MobileImpl.h"
#include <SDL2/SDL.h>
#include "libultraship/bridge/consolevariablebridge.h"

#include <imgui_internal.h>

static bool isShowingVirtualKeyboard = true;
static bool isUsingTouchscreen = false;
static float cameraYaw = 0.0f;
static float cameraPitch = 0.0f;

void Ship::Mobile::ImGuiProcessEvent(bool wantsTextInput) {
    ImGuiInputTextState* state = ImGui::GetInputTextState(ImGui::GetActiveID());

    if (wantsTextInput) {
        if (!isShowingVirtualKeyboard) {
            state->ClearText();

            isShowingVirtualKeyboard = true;
            SDL_StartTextInput();
        }
    } else {
        if (isShowingVirtualKeyboard) {
            isShowingVirtualKeyboard = false;
            SDL_StopTextInput();
        }
    }
}

bool Ship::Mobile::IsUsingTouchscreenControls() {
    return isUsingTouchscreen;
}

float Ship::Mobile::GetCameraYaw() {
    float val = cameraYaw;
    cameraYaw = 0.0f;
    return val;
}

float Ship::Mobile::GetCameraPitch() {
    float val = cameraPitch;
    cameraPitch = 0.0f;
    return val;
}

void Ship::Mobile::SetCameraYaw(float yaw) {
    cameraYaw = yaw;
}

void Ship::Mobile::SetCameraPitch(float pitch) {
    cameraPitch = pitch;
}
#endif
