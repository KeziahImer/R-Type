# EnemyInfiniteSpawn

The "EnemySpawn" addon is used to manage the generation of enemies in the game. It is used to dynamically create enemies at regular intervals. It stores the following information:

- `frequency`: The rate at which enemies are generated (expressed in time).

- `enemiesType`: A list of possible enemy types with additional information.

- `lastUpdate`: The time of the last update for enemy generation (expressed in time).

The associated system, "EnemySpawnSystem," handles the generation of enemies based on these parameters.

## Example Usage

The "EnemySpawn" component is used to dynamically generate enemies in the game by defining the generation frequency and possible enemy types.

```cpp
// Creating an EnemySpawn component
Client::Components::EnemySpawn enemySpawn;
enemySpawn.frequency = 2.0; // Enemies are generated every 2 seconds

// Defining possible enemy types
enemySpawn.enemiesType.push_back({
    /* Information about enemy 1 */
}, {
    /* Information about enemy 2 */
});

// Using the EnemySpawn component to generate enemies
```