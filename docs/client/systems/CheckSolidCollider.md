# CheckSolidCollider

The "CheckSolidCollider" system is responsible for managing collisions between solid entities in the game. It detects and handles collisions between solid entities, applying appropriate responses based on the types of collisions.

This system is essential for the physics of the game, allowing solid entities to interact correctly with each other. It supports actions such as reflection, entity removal, or applying pushing forces.

## Features
The "CheckSolidCollider" system performs the following actions:
- Detects collisions between solid entities.
- Manages the response to collisions by applying pushing forces or causing entities to explode.
- Contributes to the physics of the game by allowing solid entities to interact.

## Example Usage
The "CheckSolidCollider" system is used to manage collisions between solid entities in the game:

```cpp
// Using the CheckSolidCollider system
Client::Systems::CheckSolidCollider(core);
```