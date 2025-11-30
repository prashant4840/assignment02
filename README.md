Overview

This project is a simple console-based lane-dodging game written in C.
The player moves left/right across 3 lanes while avoiding falling obstacles.

The game is fully compatible with macOS using POSIX functions
(termios, fcntl, unistd) instead of Windows-only libraries.

⸻

Modifications Implemented (Objective 2)

I selected 3 simple enhancements from the list:

✔ 1. Score System

The score increases by 1 whenever the player successfully dodges an obstacle.

✔ 2. Player Lives

The player now has 3 lives instead of instant game over.
Lives decrease when hit by an obstacle.

✔ 3. Difficulty Levels

The falling speed increases every 5 points, making the game progressively harder.

⸻

Controls
	•	A → Move Left
	•	D → Move Right
