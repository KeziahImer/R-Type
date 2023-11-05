# CollisionWaveSpawn"
L'Addons "CollisionWaveSpawn" est utilisé pour gérer la génération de vagues de collisions dans le jeu. Il est utilisé pour créer de manière dynamique des collisions de types variés à intervalles réguliers. Il stocke les informations suivantes :

- `startSpawn`: Le moment où la génération de la vague de collisions doit commencer (exprimé en temps).


- `durationWave`: La durée totale de la vague de collisions (exprimée en temps).


- `frequence`: La fréquence à laquelle les collisions sont générées (exprimée en temps).


- `collisionsType`: Une liste de types de collisions possibles avec des informations supplémentaires.


Le système associé "CollisionWaveSpawnSystem" gère la génération des vagues de collisions en fonction de ces paramètres.

## Exemple d'utilisation
Le composant "CollisionWaveSpawn" est utilisé pour générer des vagues de collisions dynamiques dans le jeu, en définissant le moment de début, la durée et la fréquence de la vague. Les types de collisions possibles sont également définis dans la liste "collisionsType".

```cpp
// Création d'un composant CollisionWaveSpawn
Client::Components::CollisionWaveSpawn collisionWaveSpawn;
collisionWaveSpawn.startSpawn = 0; // La génération de la vague commence dès le début du jeu
collisionWaveSpawn.durationWave = 10.0; // La vague de collisions dure 10 secondes
collisionWaveSpawn.frequence = 1.0; // Les collisions sont générées toutes les 1 seconde

// Définition des types de collisions possibles
collisionWaveSpawn.collisionsType.push_back({
    /* Informations sur la collision 1 */
}, {
    /* Informations sur la collision 2 */
});

// Utilisation du composant CollisionWaveSpawn pour générer des vagues de collisions
```