# Game Systems

## Collision Check System (ShootCollisionSystem)

The Collision Check System manages collision detection between game entities. It checks if entities collide, which can trigger events like damage or destruction.

## Shoot System (ShootSystem)

The Shoot System controls the creation and behavior of projectiles fired by entities. It allows entities to fire projectiles based on player or AI input.

## Enemy Shoot System (EnemyShoot)

The Enemy Shoot System governs the behavior of enemies regarding shooting. It defines how enemies shoot projectiles, their speed, and fire rate.

## Health Check System (CheckHealth)

The Health Check System monitors entity health and performs checks to determine if they have been destroyed. It can award points to the player based on destroyed entities.

## Score Update System (UpdateScore)

The Score Update System keeps the game scores updated based on in-game events. It can update scores in real-time.

## Velocity Management System (velocitySystem)

The Velocity Management System handles the speed of entities by updating their positions based on their velocity.

## Movement Management System (MovableSystem)

The Movement Management System controls entity movement based on player or AI inputs.

## Self-Destruct System (SelfDestroy)

The Self-Destruct System manages entities that need to self-destruct when they leave predefined areas.

These systems work in harmony to create an immersive gaming experience in our R-Type game. Each has a specific role to play, contributing to the depth of gameplay.

Feel free to copy and paste this content into your documentation.

### Example of Adding Systems:
    
```cpp
  addBundle(Rtype::physicsSystems);
  addBundle(Rtype::shootsSystems);
  addBundle(Rtype::engineSystems);
```