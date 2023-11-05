# CollisionWaveSpawn

The "CollisionWaveSpawn" addon is used to manage the generation of collision waves in the game. It is used to dynamically create various types of collisions at regular intervals. It stores the following information:

- `startSpawn`: The moment when the generation of the collision wave should begin (expressed in time).

- `durationWave`: The total duration of the collision wave (expressed in time).

- `frequency`: The rate at which collisions are generated (expressed in time).

- `collisionsType`: A list of possible collision types with additional information.

The associated system, "CollisionWaveSpawnSystem," handles the generation of collision waves based on these parameters.

## Example Usage

The "CollisionWaveSpawn" component is used to generate dynamic collision waves in the game by defining the start time, duration, and frequency of the wave. The possible collision types are also defined in the "collisionsType" list.

```cpp
// Creating a CollisionWaveSpawn component
Client::Components::CollisionWaveSpawn collisionWaveSpawn;
collisionWaveSpawn.startSpawn = 0; // The wave generation begins at the start of the game
collisionWaveSpawn.durationWave = 10.0; // The collision wave lasts for 10 seconds
collisionWaveSpawn.frequency = 1.0; // Collisions are generated every 1 second

// Defining possible collision types
collisionWaveSpawn.collisionsType.push_back({
    /* Information about collision 1 */
}, {
    /* Information about collision 2 */
});

// Using the CollisionWaveSpawn component to generate collision waves
```