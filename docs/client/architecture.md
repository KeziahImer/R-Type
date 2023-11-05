# Game Architecture

This section explores the architecture of our R-Type game, developed in C++ using an Entity-Component-System (ECS) based game engine and powered by the SFML library. Understanding this architecture is essential for developers and video game enthusiasts looking to dive into our source code.

## Project Structure

Our R-Type project is organized around several key components:

1. **Entities**: Entities represent the interactive objects in the game, such as spaceships, enemies, projectiles, and other elements.

2. **Components**: Components store the data and characteristics of entities. For example, a position component, velocity component, weapon component, health component, and so on.

3. **Systems**: Systems manage the game's logic by acting on entities based on their components. For example, a rendering system uses SFML to display entities on the screen.

## Data Flow

The ECS architecture follows a specific data flow:

1. **Entity Creation**: Entities are constructed by adding relevant components. For instance, a spaceship may have position, velocity, and weapon components.

2. **System Execution**: Systems are triggered to process entities. For example, a rendering system iterates through entities and displays them on the screen using SFML.

3. **Component Updates**: Entity components are updated by systems during gameplay. For example, a movement system may change the velocity of projectiles.

4. **Interactions and Events**: Entities can interact with each other through events. For example, a projectile can inflict damage on an enemy.

## Using SFML

SFML is our library of choice for managing graphical elements, audio, and other multimedia resources. It is integrated into our game engine to create an immersive visual experience.
