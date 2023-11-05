# CheckDamage
Le système "CheckDamage" est responsable de la gestion des collisions liées aux dégâts dans le jeu. Il vérifie les collisions entre les entités attaquables (objets ou ennemis) et les entités qui infligent des dégâts (tels que les projectiles). Lorsqu'une collision est détectée, le système gère les dégâts, les points et d'autres interactions liées aux collisions.

Ce système vérifie les collisions entre les composants "Collider" (RNGine::Addons::Collider), les composants "Attackable" (RNGine::Components::Attackable) et les composants "MakeDamage" (RNGine::Components::MakeDamage) dans la scène. Il prend en compte les valeurs d'allié, de santé, de dégâts, et de points pour gérer les interactions.

## Fonctionnalités
Le système "CheckDamage" effectue les actions suivantes :
- Vérifie les collisions entre les entités attaquables et les entités qui infligent des dégâts.
- Gère les dégâts infligés en fonction des collisions détectées.
- Met à jour la santé des entités attaquables.
- Gère les points (scores) en fonction des dégâts infligés et des entités détruites.
- Supprime les entités qui ne sont plus en vie.

## Exemple d'utilisation
Le système "CheckDamage" est utilisé pour gérer les collisions et les dégâts dans le jeu :

```cpp
// Utilisation du système CheckDamage
Client::Systems::CheckCollisionsDamage(core);
```