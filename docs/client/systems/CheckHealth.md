# CheckHealth

The "CheckHealth" system is responsible for managing the health of entities in the game. It checks the health of attackable entities (objects or enemies) and takes actions in case of zero or lower health. It manages entity removal, generates loot items, and considers win or loss conditions.

This system checks the health of "Attackable" components (RNGine::Components::Attackable) and takes actions based on the current health. It generates loot items, triggers explosion animations when entities are destroyed, manages transitions to win or loss screens based on game conditions, and removes destroyed entities.

## Features
The "CheckHealth" system performs the following actions:
- Checks the health of attackable entities.
- Manages the generation of loot items based on zero or lower health.
- Triggers explosion animations when entities are destroyed.
- Manages transitions to win or loss screens based on game conditions.
- Removes entities that have no health left.

## Example Usage
The "CheckHealth" system is used to manage health and health-related interactions in the game:

```cpp
// Using the CheckHealth system
Client::Systems::CheckHealth(core);
```