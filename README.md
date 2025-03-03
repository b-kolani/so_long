# 🎮 So_Long - 42 School Project

## 🌟 Overview
     So_Long is a C programming project from the 42 School curriculum. It’s a simple 2D game built with the MiniLibX library, where a player navigates a map to collect items and reach an exit. The project focuses on graphics programming, map parsing, and basic game logic.
### Example:
     The game takes a .ber map file as input:
        ./so_long maps/valid_map.ber

## ✨ Features
    Game Elements: Player (P), walls (1), ground (0), collectibles (C), exit (E).
    Core Mechanics: Movement with WASD or arrow keys, collision detection, and win condition.
    Bonus:
        Animations for the player or collectibles.
        Enemy patrols or a move counter display.

## 🚀 Installation
    - Clone the repo:
        git clone https://github.com/b-kolani/so_long.git
    - Enter the directory:
        cd so_long
    - Compile:
        make
    - Run make bonus for the bonus features.
  
## 🖥️ Usage
    Launch the game with a map file:
        ./so_long maps/valid_map.ber
    Map Format:
        Rectangular, surrounded by walls (1).
        Contains at least one P, C, and E.
    Example:
              11111
              1P0C1
              10CE1
              11111

## 📂 Project Structure
    so_long.c	Main game loop and logic
    Makefile	Build rules with MiniLibX linking

## 🎓 Learning Outcomes
    - Learned graphics programming with MiniLibX.
    - Mastered file parsing and error handling for maps.
    - Developed skills in event handling and game design basics.

## ⚙️ Requirements
    OS: UNIX-based (Linux, macOS).
    Compiler: GCC or similar.
    MiniLibX: Graphics library (install instructions depend on OS—check 42 docs).
    (Optional): libft.

## 👤 Author
    [Kolani Biman / b-kolani]
