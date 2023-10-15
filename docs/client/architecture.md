# Architecture

Cette section plonge dans l'architecture de notre jeu R-Type, développé en C++ en utilisant un moteur de jeu basé sur une architecture ECS (Entity-Component-System) et alimenté par la bibliothèque SFML. La compréhension de cette architecture est essentielle pour les développeurs et les passionnés de jeux vidéo cherchant à explorer notre code source.

## Structure du Projet

Notre projet R-Type est organisé autour de plusieurs composants clés :

1. **Entités (Entities)** : Les entités représentent les objets interactifs du jeu, tels que les vaisseaux spatiaux, les ennemis, les projectiles, et d'autres éléments.

2. **Composants (Components)** : Les composants détiennent les données et les caractéristiques des entités. Par exemple, un composant de position, de vitesse, d'armement, de santé, etc.

3. **Systèmes (Systems)** : Les systèmes gèrent la logique du jeu en agissant sur les entités en fonction de leurs composants. Par exemple, un système de rendu utilise SFML pour afficher les entités à l'écran.

## Flux de Données

L'architecture ECS suit un flux de données spécifique :

1. **Création d'Entités** : Les entités sont construites en ajoutant les composants pertinents. Par exemple, un vaisseau peut posséder des composants de position, de vitesse, et d'armement.

2. **Exécution des Systèmes** : Les systèmes sont déclenchés pour traiter les entités. Par exemple, un système de rendu parcourt les entités et les affiche à l'écran en utilisant SFML.

3. **Mises à Jour de Composants** : Les composants des entités sont mis à jour par les systèmes au cours du jeu. Par exemple, la vitesse des projectiles est modifiée par un système de mouvement.

4. **Interactions et Événements** : Les entités peuvent interagir entre elles via des événements. Par exemple, un projectile peut infliger des dégâts à un ennemi.

## Utilisation de SFML

SFML est notre bibliothèque de choix pour la gestion des éléments graphiques, audio, et d'autres ressources multimédias. Elle est intégrée dans notre moteur de jeu pour la création d'une expérience visuelle immersive.
