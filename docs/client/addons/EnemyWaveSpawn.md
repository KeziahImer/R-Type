# EnemyWaveSpawn

The "EnemyWaveSpawn" addon is used to manage the generation of enemies in the form of waves in the game. It allows for the dynamic creation of enemy waves at regular intervals. It stores the following information:

- `startSpawn`: The moment when the generation of enemy waves should begin (expressed in time).

- `durationWave`: The total duration of the enemy wave (expressed in time).

- `frequency`: The rate at which enemy waves are generated (expressed in time).

- `enemiesType`: A list of possible enemy types with additional information.

- `lastUpdate`: The time of the last update for the generation of enemy waves (expressed in time).

- `actualDuration`: The current duration of the ongoing wave.

- `started`: An indicator to know if the generation of enemy waves has started.

The associated system, "EnemyWaveSpawnSystem," manages the generation of enemy waves based on these parameters.

## Example Usage

The "EnemyWaveSpawn" component is used to dynamically generate waves of enemy waves in the game by defining the start time, duration, generation frequency, and possible enemy types.

```cpp
// Creating an EnemyWaveSpawn component
Client::Components::EnemyWaveSpawn enemyWaveSpawn;
enemyWaveSpawn.startSpawn = 0; // The generation of the enemy wave begins at the start of the game
enemyWaveSpawn.durationWave = 30.0; // The enemy wave lasts for 30 seconds
enemyWaveSpawn.frequency = 5.0; // Enemy waves are generated every 5 seconds

// Defining possible enemy types
enemyWaveSpawn.enemiesType.push_back({
    /* Information about enemy 1 */
}, {
    /* Information about enemy 2 */
});

// Using the EnemyWaveSpawn component to generate waves of enemy waves
```