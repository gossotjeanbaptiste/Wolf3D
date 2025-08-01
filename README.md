# Wolf3D 🎮

Un jeu de tir à la première personne (FPS) inspiré de Wolfenstein 3D, développé en C avec la bibliothèque CSFML.

## 📋 Description

Wolf3D est un projet EPITECH qui reproduit l'expérience classique de Wolfenstein 3D avec un moteur de raycasting. Le joueur navigue dans un labyrinthe en vue subjective, peut combattre des ennemis et utilise une lampe de poche pour explorer les zones sombres.

## ✨ Fonctionnalités

- 🎯 **Moteur de raycasting** : Rendu 3D en temps réel
- 🔫 **Système d'armes** : Tir avec animations
- 💡 **Lampe de poche** : Éclairage dynamique avec effets visuels
- 👾 **Ennemis** : Système de monstres dans le labyrinthe
- 🎵 **Audio** : Musique de fond et effets sonores
- 🎮 **Support manette** : Compatible avec les contrôleurs DualSense
- 🗺️ **Multiples cartes** : Plusieurs niveaux disponibles
- 📱 **Interface utilisateur** : Menus de navigation intuitifs

## 🛠️ Prérequis

- **Système d'exploitation** : Linux/Windows
- **Compilateur** : GCC
- **Bibliothèques** :
  - CSFML (Simple and Fast Multimedia Library)
  - libmy (bibliothèque personnalisée incluse)

1. **Compiler le projet**

```bash
make
```

1. **Lancer le jeu**

```bash
./wolf3d
```

## 🎮 Contrôles

### Clavier & Souris

- **Z** : Avancer
- **S** : Reculer  
- **Q** : Strafer à gauche
- **D** : Strafer à droite
- **F** : Basculer la lampe de poche
- **Souris** : Regarder autour
- **Clic gauche** : Tirer
- **ESC** : Mettre en pause

### Manette DualSense

- **Stick gauche** : Se déplacer
- **Stick droit** : Regarder autour
- **R2** : Tirer
- **◻ (Carré)** : Basculer la lampe de poche
- **Start** : Mettre en pause

Pour afficher tous les contrôles :

```bash
./wolf3d -c
./wolf3d --controls
```

## 📁 Structure du Projet

```text
Wolf3D/
├── assets/                 # Ressources du jeu
│   ├── fonts/             # Polices
│   ├── map/               # Fichiers de cartes
│   ├── music/             # Fichiers audio
│   └── texture/           # Textures et sprites
├── include/               # Fichiers d'en-tête
├── lib/                   # Bibliothèques
│   ├── my/               # Bibliothèque utilitaire
│   └── my_graphical/     # Bibliothèque graphique
├── src/                   # Code source principal
│   ├── draw/             # Fonctions de rendu
│   ├── init/             # Initialisation
│   ├── input/            # Gestion des entrées
│   ├── menu/             # Interfaces utilisateur
│   └── weapon/           # Système d'armes
└── tests/                # Tests unitaires
```

## 🎯 Options de Ligne de Commande

```bash
./wolf3d [OPTION]

Options :
  -h, --help      Afficher l'aide
  -c, --controls  Afficher les contrôles
  (aucune)        Démarrer le jeu
```

## 🔧 Commandes Make

- `make` : Compiler le projet
- `make re` : Recompiler entièrement
- `make clean` : Nettoyer les fichiers objets
- `make fclean` : Nettoyage complet
- `make cs` : Vérifier le style de codage
- `make unit_tests` : Créer les tests unitaires
- `make tests_run` : Exécuter les tests

## 🗺️ Format des Cartes

Les cartes sont définies dans `assets/map/` avec le format suivant :

- `0` (Ou espace selon les fichiers de map) : Espace vide
- `1-9` : Différents types de murs
- `M` : Position des monstres

## 👥 Contributeurs

- **Jean-Baptiste GOSSOT**
- **Nathan CLAUDEL**
- **Victor JOST**

Epitech Nancy PGE 2029

## 📄 Licence

© JustWirelessInc. 2021-2029
(Fausse licence pour le projet EPITECH)

## 🐛 Problèmes Connus

- F11 (plein écran) non fonctionnel
- F4 (quitter) non fonctionnel
- Le tir prendra automatiquement compte du dernier monstre si il y a plusieurs monstres dans la ligne de mire (celui le plus au fond pas le plus proche)

## 🔗 Ressources Additionnelles

Pour tester votre contrôleur :
[Controller_Test](https://github.com/VictorTV57/Controller_Test.git)
