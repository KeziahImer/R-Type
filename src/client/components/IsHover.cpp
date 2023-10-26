#include "components/IsHover.hpp"
#include "RNGine/components/Hitbox.hpp"
#include "RNGine/components/Transform.hpp"
#include "components/MousePosition.hpp"

void Client::Components::IsHoverSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &hitboxes = scene.GetComponents<RNGine::Components::Hitbox>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &mousePositions =
      scene.GetComponents<Client::Components::MousePosition>();
  auto &isHovers = scene.GetComponents<Client::Components::IsHover>();

  auto max = isHovers.size();
  for (size_t i = 0; i < max; i++) {
    auto &hitbox = hitboxes[i];
    auto &transform = transforms[i];
    auto &mousePosition = mousePositions[i];
    auto &isHover = isHovers[i];
    if (!isHover.has_value() || !hitbox.has_value() || !transform.has_value() ||
        !mousePosition.has_value())
      continue;
    auto x = mousePosition->position.x;
    auto y = mousePosition->position.y;

    auto minX = transform->x - hitbox->originX;
    auto maxX = transform->x + hitbox->width - hitbox->originX;

    auto minY = transform->y - hitbox->originY;
    auto maxY = transform->y + hitbox->height - hitbox->originY;

    if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
      isHover->isHover = true;
    } else {
      isHover->isHover = false;
    }
  }
}
