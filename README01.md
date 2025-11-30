
This project is a simple console game written in C where the player must avoid a falling obstacle. The game uses three lanes, and the player can move left or right to dodge the obstacle. When the obstacle reaches the bottom in the same lane as the player, the game ends.

This version of the game is modified to run on macOS, since the original Windows-specific headers (conio.h, windows.h) are not available on Mac.

⸻

2. How the Game Works

Game Layout
	•	There are 3 lanes (left, middle, right).
	•	A falling obstacle (#) comes down from the top.
	•	The player (A) stays on the bottom row.
	•	The goal is to avoid the obstacle.

    Controls
	•	Press A → move left
	•	Press D → move right

⸻

3. Main Parts of the Code

3.1 Input Handling (kbhit and getch)

The game uses custom POSIX versions of kbhit() and getch() so the program can read keyboard input without waiting for Enter.
This lets the player move smoothly while the game runs.

3.2 Screen Clearing

The game uses ANSI escape codes:

printf("\033[2J\033[1;1H");

This clears the screen every frame and redraws the game area.

3.4 Collision Detection

A collision happens when:

step == 10 && x == obstaclePos

This means the falling obstacle reached the player’s row and both are in the same lane.

3.5 Game Loop

The main loop:
	1.	Checks for user input
	2.	Clears the screen
	3.	Draws the obstacle and player
	4.	Detects collision
	5.	Delays for 120ms
	6.	Moves the obstacle down

⸻

4. Logic Flow Summary
	1.	Start with a random obstacle lane
	2.	Player can move left or right
	3.	Obstacle falls row-by-row
	4.	If they collide → Game Over
	5.	Otherwise, obstacle resets and continues falling

⸻

5. Implementation Style
	•	Simple and easy-to-understand structure
	•	Uses loops and if-conditions for all logic
	•	Avoids Windows-only libraries so it works on macOS
	•	Keeps lane positions numeric (0, 1, 2) for easier comparisons
	•	Uses text-based gameplay to simulate movement