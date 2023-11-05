# Addon "Collider"

The "Collider" addon is used to handle collision detection between game entities. It keeps a list of colliding entities and provides information about the collisions, like the involved entities, hitboxes, and related transformations.
## Exemple d'utilisation

```cpp
RNGine::Addons::Collider collider;

// Define the entity's collision box (hitbox)
RNGine::Components::Hitbox hitbox;
hitbox.width = 32;
hitbox.height = 32;

// Add the collision box to the entity
entity.addComponent(hitbox);

// Apply the "Collider" addon to the entity
entity.addAddon(collider);

```