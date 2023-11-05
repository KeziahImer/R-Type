# Fonctionnement des Levels

## Mob Wave
Les mob waves représentent des vagues d'ennemis qui apparaissent à des moments spécifiques du jeu. Ils sont implémentés à l'aide du composant `Client::Components::EnemyWaveSpawn` et du système `Client::Components::EnemyWaveSpawnSystem`.

Exemple de code :
```cpp
// Création d'une mob wave
AddComponent<Client::Components::EnemyWaveSpawn>(
    CreateEntity("enemyWaveSpawn"), {8, 22, 800, {ENEMY_TYPE_1}});
```

## Power-up
Les power-ups sont des objets que le joueur peut collecter pour obtenir des avantages. Le code spécifique pour les power-ups n'est pas fourni, mais ils peuvent être mis en place de manière similaire aux autres éléments.

## Drop Item
Les drop items sont des objets que les ennemis laissent tomber lorsque le joueur les détruit. Le code pour la gestion des drop items n'est pas fourni, mais il serait géré par des composants et des systèmes similaires à ceux des power-ups.

## Boss
Les boss sont des ennemis puissants qui sont généralement plus gros et plus difficiles à vaincre. Ils sont implémentés à l'aide du composant `Client::Components::EnemyWaveSpawn` et du système `Client::Components::EnemyWaveSpawnSystem`.

Exemple de code :

```cpp
// Création d'un boss
AddComponent<Client::Components::EnemyWaveSpawn>(
    CreateEntity("enemyWaveSpawn"), {60, 1, 1500, {BOSS_TYPE_1}});
```

## Obstacle
Les obstacles sont des éléments du décor qui peuvent bloquer le mouvement du joueur ou des ennemis. Le code spécifique pour les obstacles n'est pas fourni, mais ils seraient gérés de manière similaire aux autres entités du jeu.