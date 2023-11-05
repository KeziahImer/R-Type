# Level

## Mob Waves

Mob waves represent waves of enemies that appear at specific moments in the game. They are implemented using the `Client::Components::EnemyWaveSpawn` component and the  `Client::Components::EnemyWaveSpawnSystem` system.

Exemple de code :
```cpp
// Creating a mob wave
AddComponent<Client::Components::EnemyWaveSpawn>(
CreateEntity("enemyWaveSpawn"), {8, 22, 800, {ENEMY_TYPE_1}});
```

## Power-up
Power-ups are objects that players can collect to gain advantages. Specific code for power-ups is not provided, but they can be set up in a similar manner to other game elements.
## Drop Item
Drop items are objects that enemies leave behind when destroyed by the player. Specific code for managing drop items is not provided, but they would be handled by components and systems similar to power-ups.
## Boss
Bosses are powerful enemies that are typically larger and more challenging to defeat. They are implemented using the `Client::Components::EnemyWaveSpawn` component and the  `Client::Components::EnemyWaveSpawnSystem` system.

Example code:

```cpp
// Creating a boss
AddComponent<Client::Components::EnemyWaveSpawn>(
CreateEntity("enemyWaveSpawn"), {60, 1, 1500, {BOSS_TYPE_1}});
```

## Obstacle
Obstacles are environmental elements that can block the movement of players or enemies. Specific code for obstacles is not provided, but they would be managed similarly to other game entities.