# EnemyInfiniteSpawn
Le composant "EnemySpawn" est utilisé pour gérer la génération d'ennemis dans le jeu. Il est utilisé pour créer de manière dynamique des ennemis à intervalles réguliers. Il stocke les informations suivantes :

- `frequence`: La fréquence à laquelle les ennemis sont générés (exprimée en temps).


- `enemiesType`: Une liste de types d'ennemis possibles avec des informations supplémentaires.


- `lastUpdate`: Le moment de la dernière mise à jour de la génération d'ennemis (exprimé en temps). 


Le système associé "EnemySpawnSystem" gère la génération des ennemis en fonction de ces paramètres.

## Exemple d'utilisation
Le composant "EnemySpawn" est utilisé pour générer des ennemis de manière dynamique dans le jeu, en définissant la fréquence de génération et les types d'ennemis possibles.

```cpp
// Création d'un composant EnemySpawn
Client::Components::EnemySpawn enemySpawn;
enemySpawn.frequence = 2.0; // Les ennemis sont générés toutes les 2 secondes

// Définition des types d'ennemis possibles
enemySpawn.enemiesType.push_back({
    /* Informations sur l'ennemi 1 */
}, {
    /* Informations sur l'ennemi 2 */
});

// Utilisation du composant EnemySpawn pour générer des ennemis
```