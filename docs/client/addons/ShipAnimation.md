# ShipAnimation

The "ShipAnimation" addon is used to manage the animation of movements for a spaceship in the game. It allows for controlling animations based on the spaceship's actions, such as moving up, moving down, or stopping (none). This component stores the following information:

- `lastAction`: The last action performed by the spaceship, which can have values of None, Up, or Down to represent movements.

The associated "ShipAnimationSystem" manages the spaceship's animations based on these actions by modifying the spaceship's sprite animations.

## Example Usage

The "ShipAnimation" component is used to control the animations of the spaceship based on its movements:

```cpp
// Creating a ShipAnimation component
Client::Addons::ShipAnimation shipAnimation;
shipAnimation.lastAction = Client::Addons::ShipAnimation::None; // The spaceship is not moving initially

// Using the ShipAnimation component to control animations for the spaceship
```