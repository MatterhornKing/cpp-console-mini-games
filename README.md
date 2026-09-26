# C++ Console Mini Games

A collection of console-based mini-games developed as an early C++ programming project.

The project contains five games implemented from scratch using C++ and the Windows Console API. It was originally developed in Code::Blocks and focuses on fundamental programming concepts such as game loops, keyboard input, state updates, collision detection, and two-dimensional array manipulation.

Each game is separated into its own source and header files, while Common.cpp and Common.h contain shared Windows console utilities.

## Games

### Snake

A console implementation of the classic Snake game.

Features include:
- WASD movement with prevention of immediate reverse-direction moves
- Random food generation
- Multiple collectible items with different effects
- Health and scoring systems
- Temporary speed changes
- Collision detection with walls and the snake itself

### Plane War

A simple console shooting game in which the player controls an aircraft and fights incoming enemies.

Features include:
- WASD aircraft movement
- Player and enemy projectiles
- Collision detection
- Health and scoring systems
- Increasing difficulty as the score increases
- A final boss with horizontal movement

### Brick Breaker

A console-based brick-breaking game.

Features include:
- A movable paddle controlled by the player
- Ball movement and collision handling
- Randomly generated bricks
- Special bricks that award additional points
- Score tracking

### Flappy Bird

A console recreation of the basic Flappy Bird game mechanics.

Features include:
- Gravity-based bird movement
- Space-bar controlled jumping
- Randomly generated obstacle gaps
- Increasing difficulty through smaller gaps and faster game speed
- Score tracking

### Conway's Game of Life

An implementation of Conway's Game of Life using a two-dimensional grid.

Features include:
- Random initial cell configurations
- Generation updates based on neighbouring cells
- Separate current-state and next-state grids
- A predefined Gosper Glider Gun configuration

## Technologies

- C++
- Windows Console API
- Code::Blocks

## Running the Project

This project was originally developed for Windows using Code::Blocks and relies on Windows-specific console APIs such as `windows.h` and `conio.h`.

Open `MyGames.cbp` in Code::Blocks on Windows to build and run the project.

The project is not designed to compile natively on macOS or Linux without modification.

## How to Play

From the main menu, press `1`–`5` to select a game.

| Game | Controls |
| --- | --- |
| Snake | `W` `A` `S` `D` to move |
| Plane War | `W` `A` `S` `D` to move, `Space` to shoot |
| Brick Breaker | `W` `A` `S` `D` to move the paddle |
| Flappy Bird | `Space` to jump |
| Game of Life | Select an initial configuration from its menu; press `Space` to return |

Press `Esc` on the main menu to exit the program.