
#include "components/IsClicked.hpp"
#include "components/IsHover.hpp"
#include "components/MousePosition.hpp"

void Client::Components::IsClickedSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &isClickeds = scene.GetComponents<Client::Components::IsClicked>();
  auto &isHovers = scene.GetComponents<Client::Components::IsHover>();
  auto &mousePositions =
      scene.GetComponents<Client::Components::MousePosition>();

  auto max = isHovers.size();
  for (size_t i = 0; i < max; i++) {
    auto &isClicked = isClickeds[i];
    auto &isHover = isHovers[i];
    auto &mousePosition = mousePositions[i];
    if (!isClicked.has_value() || !isHover.has_value() ||
        !mousePosition.has_value())
      continue;

    if (isHover->isHover) {
      if (mousePosition->right_click) {
        isClicked->IsClickedRight = true;
      } else {
        isClicked->IsClickedRight = false;
      }
      if (mousePosition->left_click) {
        isClicked->IsClickedLeft = true;
      } else {
        isClicked->IsClickedLeft = false;
      }
    }
  }
}
