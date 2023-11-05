# Addon Limits

The "Limits" addon is used to set boundaries for entities' movement. It specifies the minimum and maximum values for position, speed, and acceleration in the horizontal (x) and vertical (y) directions. This helps restrict where entities can move within specific areas of the game.
## Example of use

```cpp
RNGine::Addons::Limits limits;

limits.minX = 0.0f;    // Minimum position in the horizontal (x) direction
limits.maxX = 800.0f;  // Maximum position in the horizontal (x) direction
limits.minY = 0.0f;    // Minimum position in the vertical (y) direction
limits.maxY = 600.0f;  // Maximum position in the vertical (y) direction

// Apply the limits to an entity
entity.addAddon(limits);
```