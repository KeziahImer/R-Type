# SpriteAnimation

The "SpriteAnimation" addon is used to manage sprite animations in the game. It allows for creating animations by scrolling through images in a texture at regular intervals. This component stores the following information:

- `reverse`: A boolean indicating if the animation should be reversed (true) or not (false).

-`loop`: A boolean indicating if the animation should repeat in a loop (true) or stop after a single iteration (false).

-`multiple`: A boolean indicating if the animation has multiple image sequences (true) or a single sequence (false).

-`finish`: A boolean indicating if the animation has reached its end (true) or is in progress (false).

-`start`: A pair of integers (x, y) representing the first image of the animation.

-`end`: A pair of integers (x, y) representing the last image of the animation.

-`lastFrame`: A pair of integers (x, y) representing the last displayed image.

-`frequency`: The time in milliseconds between each image change in the animation.

-`lastUpdate`: The time in milliseconds since the last animation update.

The associated "SpriteAnimationSystem" manages the updating of sprite animations based on time and the parameters defined in this component.

## Example Usage

The "SpriteAnimation" component is used to create sprite animations in the game:

```cpp
// Creating a SpriteAnimation component
Client::Components::SpriteAnimation animation;
animation.reverse = false; // The animation is not reversed
animation.loop = true; // The animation repeats in a loop
animation.multiple = true; // The animation has multiple image sequences
animation.finish = false; // The animation is in progress
animation.start = std::make_pair(0, 0); // First image of the animation
animation.end = std::make_pair(3, 3); // Last image of the animation
animation.lastFrame = std::make_pair(0, 0); // Last displayed image
animation.frequency = 100; // Image change every 100 milliseconds
animation.lastUpdate = 0; // Time elapsed since the last update

// Using the SpriteAnimation component to manage a sprite animation
```