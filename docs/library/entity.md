# Entity Management (Entities)

In our R-Type game, entities play a central role. Entities represent objects in the game world, such as spaceships, enemies, projectiles, and various other interactive elements. Understanding how entities are managed is essential for any developer working on our game.

## Creating Entities

Entities are created dynamically during the game. Each entity is associated with a unique identifier and is composed of multiple components that define its characteristics.

### Example of Creating an Entity:

```cpp
createPlayer(createEntity("player")); 
addComponent(e, RNGine::components::Position::createPosition(x, y));
addComponent(e, RNGine::components::Size::createSize(scaleWidth, scaleHeight));
```
## Using Entities

Entities are updated and managed by the systems of the ECS architecture. Systems act on entities based on the associated components.

### Example of Using Entities:

```cpp
RNGine::Entity Registry::getEntity(std::string const &name) {
    auto it = _entities.find(name);
    if (it != _entities.end()) {
        return it->second;
    }
    throw std::runtime_error("Entity not found in registry.");
}
```

## Destroying Entities

Entities can be destroyed when they are no longer needed. Associated components are removed, freeing up resources.

### Example of Destroying an Entity:

```cpp
void Registry::removeEntity(RNGine::Entity entity) {
    for (auto remove : _removes) {
        remove.second(*this, entity);
    }
}
```

## Interaction Between Entities

Entities can interact with each other, for example, projectiles may inflict damage on other entities. This interaction is managed by the systems and events within the game.

## Summary

The management of entities is a key element of the ECS architecture of our R-Type game. Entities are created dynamically, updated by systems, and potentially destroyed during the game. They form the foundation of the gaming experience and are essential for creating an interactive and dynamic world.