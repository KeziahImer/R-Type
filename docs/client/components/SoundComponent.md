# SoundComponent
Le composant "SoundComponent" est utilisé pour gérer la lecture des fichiers audio (sons) dans le jeu. Il permet de spécifier un fichier audio à lire, de contrôler la lecture, la répétition et le volume du son. Ce composant est principalement utilisé pour l'ajout d'effets sonores ou de musique dans le jeu.
Ce composant contient les informations suivantes :

- `path`: Une chaîne de caractères représentant le chemin du fichier audio à lire. Cela peut être un fichier audio au format WAV, MP3, etc.


- `play`: Un indicateur booléen qui spécifie si le son doit être lu (true) ou non (false).


- `loop`: Un indicateur booléen qui spécifie si le son doit être lu en boucle (true) ou non (false).


- `stop`: Un indicateur booléen qui spécifie si le son doit être arrêté (true) ou non (false).


- `volume`: Un nombre à virgule flottante représentant le volume du son (de 0 à 100, 100 étant le volume maximal).


Ce composant permet de contrôler la lecture des fichiers audio dans le jeu, en spécifiant le fichier à lire, s'il doit être lu en boucle, son volume, et s'il doit être arrêté. Il est utilisé pour ajouter des effets sonores et de la musique dans le jeu, améliorant ainsi l'expérience audio des joueurs.

## Exemple d'utilisation
Le composant "SoundComponent" est utilisé pour gérer la lecture des fichiers audio dans le jeu :

```cpp
// Création d'un composant SoundComponent
Client::Components::SoundComponent sound;

// Spécification du chemin du fichier audio
sound.path = "audio/mysound.wav";

// Lecture du son
sound.play = true;

// Réglage du volume
sound.volume = 50; // Réglage du volume à 50%

// Lecture en boucle
sound.loop = true;

// Arrêt de la lecture
sound.stop = false;

// Utilisation du composant SoundComponent pour gérer la lecture audio

```