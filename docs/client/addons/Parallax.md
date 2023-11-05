# Parallax

The "Parallax" addon is used to manage parallax effects in the game. Parallax is a graphic animation technique that creates an illusion of depth by scrolling different background layers at different speeds. This component stores the following information:

- `position`: A pair of values (x, y) representing the position of the parallax effect.

The associated "ParallaxSystem" manages the update of the parallax effect's position based on the game's progression, creating a visual background scrolling effect.

## Example Usage

The "Parallax" component is used to create parallax effects in the game:

```cpp
// Creating a Parallax component
Client::Components::Parallax parallax;
parallax.position = {0, 0}; // Initial position of the parallax effect

// Using the Parallax component to manage the parallax effect
```