
#include "SetMousePosition.hpp"

void Client::SetMousePosition(RNGine::Scene &scene) {
  auto &components = scene.GetComponents<Client::Components::MousePosition>();
  r::Vector2 mousePosition = r::GetMousePosition();
  bool left_click = r::IsMouseButtonPressed(r::MOUSE_LEFT_BUTTON);
  bool right_click = r::IsMouseButtonPressed(r::MOUSE_RIGHT_BUTTON);

  for (auto &component : components) {
    if (!component.has_value())
      continue;
    component->position = mousePosition;
    component->left_click = left_click;
    component->right_click = right_click;
  }
}
