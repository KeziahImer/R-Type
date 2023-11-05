# Gestion des Scènes

Dans R-Type, la gestion des scènes vous permet d'organiser et de contrôler les différentes parties du jeu, comme le menu principal, les niveaux et les écrans de fin.

## Vue d'ensemble

La classe `Scene` de notre moteur de jeu offre les fonctionnalités suivantes :

- Création d'objets (entités) pour le jeu.
- Ajout de paquets de systèmes pour gérer le gameplay.
- Chargement et déchargement de scènes pour changer l'état du jeu.

## Comment ça Fonctionne

- Créez des entités pour représenter des éléments du jeu tels que des vaisseaux et des ennemis en utilisant `createEntity`.

- Accédez à des entités spécifiques par leur nom ou identifiant avec `getEntity`.

- Ajoutez des paquets de systèmes pour gérer divers aspects du jeu, tels que la physique et les entrées.

- Chargez ou déchargez des scènes pour basculer entre différentes parties du jeu.

- Mettez à jour la scène pour faire progresser le gameplay en réagissant aux actions des joueurs.

- Chaque scène peut être identifiée de manière unique.

## Exemple d'Utilisation

Voici un exemple de la manière dont vous pourriez utiliser la classe `Scene` de notre moteur de jeu pour gérer les scènes :

```cpp
RNGine::Entity playerEntity = currentScene.createEntity("player");

RNGine::Registry::SystemBundle physicsBundle = {PhysicsSystem};
currentScene.addBundle(physicsBundle);

currentScene.load();

std::map<enum RNGine::Key, bool> keybinds = getInput();
currentScene.update(keybinds);
```