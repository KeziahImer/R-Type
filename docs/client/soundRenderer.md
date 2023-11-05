# SoundRenderer
Le module "SoundRenderer" est responsable de la gestion des effets sonores et de la musique du jeu. Il permet de charger, jouer, mettre en pause et arrêter des fichiers audio en fonction des événements du jeu, créant ainsi une expérience sonore immersive pour le joueur.

Le rendu sonore est essentiel pour ajouter une dimension sensorielle au jeu, en fournissant des rétroactions audio en réponse aux actions du joueur et aux événements du jeu.

## Fonctionnalités
Le module "SoundRenderer" effectue les actions suivantes :

- Charge les fichiers audio à partir de chemins spécifiés.


- Joue les effets sonores ou la musique en fonction des signaux reçus depuis la scène du jeu.


- Gère le volume sonore des fichiers audio en fonction des paramètres spécifiés.


- Met en pause, reprend et arrête la lecture des fichiers audio lorsque cela est requis.


## Exemple d'utilisation
Le module "SoundRenderer" est utilisé pour gérer les effets sonores et la musique dans le jeu :

```cpp
// Création d'une instance de SoundRenderer
Client::SoundRenderer soundRenderer;

// Dans la boucle principale du jeu
while (!r::WindowShouldClose()) {
    // ...
    soundRenderer.UpdateSounds(core.GetActualScene()); // Gère les effets sonores et la musique
    // ...
}
```