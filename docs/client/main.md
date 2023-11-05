# Main

### 1.  Initialisation de la fenêtre et du son :

- `r::InitWindow(1920, 1080, "Super Mega Rtype")` initialise une fenêtre de jeu d'une résolution de 1920x1080 pixels et lui donne un titre.


- `r::InitAudioDevice()` initialise le système audio.


- `r::SetMasterVolume(100)` règle le volume audio principal à 100 %.


- `r::ToggleFullscreen()` bascule en mode plein écran.


- `r::DisableCursor()` désactive le curseur de la souris dans la fenêtre.


### 2. Création d'objets de rendu, de son et de réseau :

- `Client::Renderer` renderer est un objet responsable du rendu graphique du jeu.


- `Client::SoundRenderer` soundRenderer est un objet pour gérer les effets sonores.


- `Client::TextRenderer` textRenderer gère l'affichage de texte à l'écran.


- `Client::Networker networker` est un objet pour gérer la communication réseau.


### 3. Initialisation du moteur de jeu RNGine :

- `RNGine::Core` core initialise le moteur de jeu principal.


- Différentes scènes du jeu sont créées, telles que "Home", "Game", "Level1", "Level2", etc., chacune étant associée à une instance de classe de scène spécifique.


### 4. Ajout de scènes et de systèmes :

- `core.AddScene(...)` ajoute les scènes créées au moteur de jeu.


- `core.AddSystem(...)` ajoute des systèmes au moteur de jeu pour gérer des fonctionnalités spécifiques.


### 5. Boucle de jeu principale :

- Une boucle `while` vérifie si la fenêtre doit être fermée. Tant que la fenêtre n'est pas fermée, la boucle continue à s'exécuter.


- Dans la boucle, `core.Update()` est appelé pour mettre à jour l'état des entités et exécuter les systèmes.


- Ensuite, la boucle rend la scène actuelle en appelant `renderer.RenderSprites()`, met à jour les sons avec `soundRenderer.UpdateSounds()`, affiche du texte avec `textRenderer.UpdateTexts()`, et gère la position de la souris avec `Client::SetMousePosition()`.


- Enfin, la boucle met à jour la communication réseau avec networker.Update().


### 6. Fermeture du jeu :

- Après la sortie de la boucle principale, le code ferme le dispositif audio avec `r::CloseAudioDevice()`.


- Ensuite, la fenêtre de jeu est fermée avec `r::CloseWindow()`.


### 7. Valeur de retour :

La fonction main renvoie 0 pour indiquer une sortie normale du programme.