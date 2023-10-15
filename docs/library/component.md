# Components

In our R-Type game, components are essential building blocks that define the characteristics and behaviors of entities. Each entity is composed of various components, which collectively determine its functionality within the game. Understanding how components are used and managed is crucial for developers working on our project.

## Attackable

The Attackable component defines attributes related to an entity's vulnerability to damage. It includes properties like hit points, defensive capabilities, and interactions with offensive components.

## Collider

The Collider component is responsible for managing an entity's collision properties. It defines the collision shape, size, and behaviors, crucial for interactions between entities and the game environment.

## EnemyShoot

The EnemyShoot component is used to specify attributes related to an entity's shooting behavior. It defines the type of projectiles, firing rates, and targeting characteristics for entities that can shoot at the player or other entities.

## MakeDamage

The MakeDamage component represents an entity's ability to inflict harm or damage to other entities. It defines the damage output, attack range, and other characteristics necessary for combat.

## Movable

The Movable component handles an entity's movement capabilities. It specifies the entity's speed, direction, and behaviors related to navigation and mobility within the game.

## SelfDestroy 

The SelfDestroy component is used to manage an entity's behavior when it needs to self-destruct or be removed from the game. It includes properties related to removal conditions and effects.

## Shoot

The Shoot component defines an entity's ability to fire projectiles or attacks. It includes characteristics such as the type of ammunition, firing patterns, and targeting behavior.

## Size

The Size component specifies the dimensions of an entity, such as its width and height. It influences the entity's visual representation and collision detection.

## Sprite

The Sprite component is responsible for the visual appearance of an entity. It defines the graphical representation, texture, and appearance of the entity in the game.

## Velocity

The Velocity component represents an entity's speed and direction of movement. It controls how an entity moves within the game world.

## Text

The Text component is used to handle textual information related to an entity, such as labels, descriptions, or other text-based attributes associated with the entity.


### Example of Adding Components to an Entity:

```cpp
addComponent(e, RNGine::components::Sprite::createSprite("./assets/Player.gif", false, 33, 17, 2, 2, 2));
addComponent(e, RNGine::components::Position::createPosition(25, 500));
addComponent(e, RNGine::components::Size::createSize(3, 3));
addComponent(e, RNGine::components::Velocity::createVelocity(0, 0));
addComponent(e, RNGine::components::Collider::createCollider(33 * 3, 17 * 3));
```

## Summary

Components are fundamental to the architecture of our R-Type game. They define the attributes and behavior of entities, allowing for the creation of complex and dynamic gameplay. Understanding how to add, remove, and utilize components is essential for game development in our project.