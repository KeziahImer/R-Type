# EnemyWaveSpawn
L'Addons "EnemyWaveSpawn" est utilisé pour gérer la génération d'ennemis sous forme de vagues dans le jeu. Il permet de créer des vagues d'ennemis de manière dynamique à intervalles réguliers. Il stocke les informations suivantes :

- `startSpawn`: Le moment où la génération de la vague de vagues doit commencer (exprimé en temps).


- `durationWave`: La durée totale de la vague de vagues (exprimée en temps).


- `frequence`: La fréquence à laquelle les vagues de vagues sont générées (exprimée en temps).


- `enemiesType`: Une liste de types d'ennemis possibles avec des informations supplémentaires.


- `lastUpdate`: Le moment de la dernière mise à jour de la génération de vagues de vagues (exprimé en temps).


- `actualDuration`: La durée actuelle de la vague en cours.


- `started`: Un indicateur pour savoir si la génération de vagues de vagues a commencé.
Le système associé "EnemyWaveSpawnSystem" gère la génération des vagues de vagues d'ennemis en fonction de ces paramètres.

## Exemple d'utilisation
Le composant "EnemyWaveSpawn" est utilisé pour générer des vagues de vagues d'ennemis de manière dynamique dans le jeu, en définissant le moment de début, la durée, la fréquence de génération et les types d'ennemis possibles.

```cpp
// Création d'un composant EnemyWaveSpawn
Client::Components::EnemyWaveSpawn enemyWaveSpawn;
enemyWaveSpawn.startSpawn = 0; // La génération de la vague de vagues commence dès le début du jeu
enemyWaveSpawn.durationWave = 30.0; // La vague de vagues d'ennemis dure 30 secondes
enemyWaveSpawn.frequence = 5.0; // Les vagues de vagues d'ennemis sont générées toutes les 5 secondes

// Définition des types d'ennemis possibles
enemyWaveSpawn.enemiesType.push_back({
    /* Informations sur l'ennemi 1 */
}, {
    /* Informations sur l'ennemi 2 */
});

// Utilisation du composant EnemyWaveSpawn pour générer des vagues de vagues d'ennemis
```