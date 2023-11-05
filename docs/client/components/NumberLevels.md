# NumberLevel Component

The "NumberLevel" component is used to store the level number in the game. It allows tracking the current level number that the player is currently playing. This component stores the following information:

- `numberLevel`: An integer representing the current level number in the game.

This component is useful for tracking and displaying the current level number that the player is playing, which can be helpful in the user interface or for managing game progression.

## Example Usage

The "NumberLevel" component is used to track and display the current level number:

```cpp
// Creating a NumberLevel component
Client::Components::NumberLevel level;
level.numberLevel = 1; // The player is currently playing level 1

// Using the NumberLevel component to display the level number
```