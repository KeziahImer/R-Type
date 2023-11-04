# SendPacket
Le composant "SendPacket" est utilisé pour stocker des paquets de données à envoyer via le réseau dans le jeu. Il contient une liste de paquets à envoyer. Ce composant est principalement utilisé pour gérer la communication réseau dans le jeu, en stockant les paquets de données à transmettre.

Ce composant contient les informations suivantes :

- `packets`: Un vecteur (tableau dynamique) de paquets réseau (de type `Network::Packet`) à envoyer. Chaque paquet peut contenir des données spécifiques à envoyer à d'autres clients ou serveurs.


Ce composant est essentiel pour la communication réseau dans le jeu, en permettant de stocker et de gérer les données à envoyer aux autres joueurs ou serveurs. Il est utilisé pour envoyer des informations, des commandes ou des mises à jour via le réseau.

## Exemple d'utilisation
Le composant "SendPacket" est utilisé pour stocker des paquets de données à envoyer via le réseau :ssentiel pour la communication réseau dans le jeu, en permettant de stocker et de gérer les données à envoyer aux autres joueurs ou serveurs. Il est utilisé pour envoyer des informations, des commandes ou des mises à jour via le réseau.

```cpp
// Création d'un composant SendPacket
Client::Components::SendPacket sendPacket;

// Création de paquets réseau et ajout à la liste de paquets
Network::Packet packet1;
packet1 << "Données du paquet 1";
sendPacket.packets.push_back(packet1);

Network::Packet packet2;
packet2 << 42; // Exemple de données (entier)
sendPacket.packets.push_back(packet2);

// Envoi des paquets via le réseau
// ...

// Utilisation du composant SendPacket pour gérer les paquets à envoyer
```