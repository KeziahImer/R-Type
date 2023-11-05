# Networker
Le module "Networker" est responsable de la gestion des communications réseau dans le jeu. Il permet d'envoyer et de recevoir des paquets réseau pour synchroniser les informations entre le client et le serveur.

Ce module est essentiel pour permettre au jeu d'interagir avec un serveur distant, d'envoyer des données et de recevoir des réponses, notamment pour l'authentification du joueur.

## Fonctionnalités
Le module "Networker" effectue les actions suivantes :

- Initialise la connexion avec le serveur en résolvant l'adresse et le port.


- Met à jour la communication réseau en envoyant et recevant des paquets.


- Attends une réponse d'authentification du serveur lorsque la scène actuelle est "lobby".
## Exemple d'utilisation
Le module "Networker" est utilisé pour gérer les communications réseau dans le jeu :

```cpp
// Création d'une instance de Networker
Client::Networker networker;

// Dans la boucle principale du jeu
while (!r::WindowShouldClose()) {
    // ...
    networker.Update(core); // Met à jour la communication réseau
    // ...
}
```