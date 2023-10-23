
#include "SetMousePosition.hpp"

void Client::SetMousePosition(RNGine::Scene &scene) {
  auto &components = scene.GetComponents<Client::Components::MousePosition>();
  Vector2 mousePosition = GetMousePosition();
  bool left_click = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
  bool right_click = IsMouseButtonPressed(MOUSE_RIGHT_BUTTON);

  for (auto &component : components) {
    if (!component.has_value())
      continue;
    component->position = mousePosition;
    component->left_click = left_click;
    component->right_click = right_click;
  }
}
