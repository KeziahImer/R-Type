# Addon Velocity


The "Velocity" addon is used to control the speed of entities in both the horizontal (x) and vertical (y) directions. It allows you to set the movement speed of entities.

## Example of use

```cpp
RNGine::Addons::Velocity velocity;

velocity.x = 2.0f;  // Horizontal speed
velocity.y = 1.5f;  // Vertical speed

// Apply the velocity to an entity
entity.addAddon(velocity);
```