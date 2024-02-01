
# Memory Game

This project introduces a Memory Game, a classic game that challenges players to find pairs of identical cards. The game begins with all cards shuffled and placed face down. Players turn over two cards at a time, with the goal of finding all pairs in the least amount of time possible.

## Game Overview

- The game features pairs of cards with identical illustrations.
- Players reveal two cards each turn:
  - If the cards match, they remain face up.
  - If the cards do not match, they are briefly visible before being turned face down again, during which time no actions can be taken.
- The objective is to uncover all pairs in the shortest time.

## Features

- **Mouse Interaction:** Cards are flipped by clicking with the mouse.
- **Timer:** The game tracks the elapsed time in seconds from the start of the game.
- **Adjustable Grid Size:** Players can choose to play on grids of various sizes.
- **Memory Time:** Players have a second to memorize a pair of revealed cards before they are turned face down again if they don't match.
- **Cheat Mode:** Pressing the `t` key reveals all cards and pauses the timer until pressed again to resume the game.
  
## Commands

- `make & make build`: Compiles the project.
- `make run`: Compiles the project and launches the game.
- `make clean`: Removes all files related to the compilation.
