# CheckDamage

The "CheckDamage" system is responsible for managing damage-related collisions in the game. It checks for collisions between attackable entities (objects or enemies) and entities that inflict damage (such as projectiles). When a collision is detected, the system handles damage, points, and other interactions related to collisions.

This system checks for collisions between the "Collider" components (RNGine::Addons::Collider), "Attackable" components (RNGine::Components::Attackable), and "MakeDamage" components (RNGine::Components::MakeDamage) in the scene. It takes into account ally values, health, damage, and points to manage interactions.

## Features
The "CheckDamage" system performs the following actions:
- Checks for collisions between attackable entities and entities that inflict damage.
- Manages inflicted damage based on detected collisions.
- Updates the health of attackable entities.
- Manages points (scores) based on inflicted damage and destroyed entities.
- Removes entities that are no longer alive.

## Example Usage
The "CheckDamage" system is used to manage collisions and damage in the game:

```cpp
// Using the CheckDamage system
Client::Systems::CheckCollisionsDamage(core);
```