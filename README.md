
# 🧱 Cub3D

**Projet 42 - École 42 Lyon**  
Implémentation d’un moteur 3D minimaliste en **C**, inspiré du jeu *Wolfenstein 3D*.  
L’objectif est d’appliquer les principes du **raycasting** pour générer une scène 3D à partir d’une carte 2D.

---

## 🧠 Description

Le programme projette en 3D un environnement 2D grâce au **raycasting**, en simulant la vue subjective d’un joueur dans un labyrinthe.  
Chaque rayon détecte les collisions avec les murs et calcule leur distance pour déterminer la hauteur des colonnes à afficher à l’écran.  

Ce projet permet de comprendre les **fondements du rendu 3D**, la **gestion des textures**, et les **calculs trigonométriques** utilisés dans les moteurs de jeu.

---

## ⚙️ Fonctionnalités principales

- Rendu en 3D basé sur le **raycasting**  
- Lecture et interprétation d’une carte (`.cub`)  
- Gestion des **textures**, **murs**, **sols** et **plafonds**  
- Déplacements du joueur avec détection des **collisions**  
- Affichage fluide via **MiniLibX** (librairie graphique 42)  
- Gestion du clavier et des angles de vision  
- Parsing robuste des fichiers de configuration  

---

## 🧰 Compétences développées

- Trigonométrie appliquée (sin, cos, angle FOV)  
- Mathématiques du **raycasting**  
- Optimisation des calculs et gestion de la mémoire  
- Programmation événementielle et graphique  
- Parsing de fichiers et manipulation de structures complexes  

---

## 🛠️ Compilation

Utilisez le **Makefile** :
```bash
make
```

Lancez le programme avec une carte valide :
```bash
./cub3D maps/example.cub
```

---

## 📸 Exemple visuel
<img width="3790" height="1947" alt="Screenshot from 2025-10-21 21-56-06" src="https://github.com/user-attachments/assets/32fde89f-aa0c-40ca-962d-ea7076d8e4de" />

