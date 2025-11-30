Assignment 02 README

Objective 2 — Implement Modifications

For Objective 2, I selected three enhancements from the allowed modification list to improve the original Lane Dodger game. Since one of the features is a High-Level modification, it counts as two changes, fulfilling the requirement:

✔ 1 High-Level + 1 Simple feature = 3 total modifications

Below are the modifications I implemented.

⸻

Modification 1 — Shooting Mechanic (High‑Level)

(Counts as TWO modifications)

I added a shooting feature where the player can press SPACE to fire bullets upward. Bullets travel up the screen and destroy enemies on contact.

What was added:
	•	Bullet movement system
	•	Bullet storage (lane + row)
	•	Bullet vs enemy collision detection
	•	Bullet rendering using |
	•	Shooting sound (\a)
	•	Bonus points for destroying enemies

Why this is High‑Level:

This feature required brand‑new mechanics, collision rules, rendering updates, and input handling, making it significantly more complex than simple modifications.

⸻

Modification 2 — Score System (Simple)

A score counter now increases when the player dodges enemies or destroys them with bullets.

Scoring:
	•	+1 for dodging an enemy
	•	+2 for shooting an enemy

The score is displayed at the top of the screen.

⸻

Modification 3 — Improved Icons / Visual Representation (Simple)

I updated the game’s visuals to make everything clearer and more modern.

New Icons:
	•	Player → A
	•	Enemy → X
	•	Bullet → |
	•	Cleaner spacing and lane layout

Why this improves the game:

The new graphics make the game easier to read and more enjoyable to play.

⸻
Summary of Modifications

Feature	Category	Count
Shooting mechanic	High‑Level	2
Score system	Simple	1
Improved visuals	Simple	(extra improvement)

Total = 3+ modifications (requirement satisfied).

Objective 2 — Implemented Modifications (3 Simple Features)

For Objective 2, I selected three simple enhancements from the modification list. These upgrades improve gameplay without adding high-level or advanced systems.

⸻

1. Score System (Simple)

I added a score counter that increases each time the player successfully dodges a falling obstacle.
	•	The score is shown at the top of the screen.
	•	Players earn +1 point per dodge.
	•	The final score is displayed when the game ends.

⸻

2. Player Lives (Simple)

The player now has 3 lives instead of losing instantly.
	•	A life is lost when the obstacle hits the player.
	•	The game ends only when all 3 lives are gone.
	•	Lives are displayed next to the score.

This makes the game more forgiving and more fun to play.

⸻

3. Difficulty Increase (Simple)

I added a dynamic difficulty system to make the game progressively harder.
	•	Every 5 points, the game becomes slightly faster.
	•	The falling speed is controlled by reducing the delay value.
	•	There is a limit so the game never becomes impossible.

⸻

Summary of Modifications

Feature	Type	Count
Score System	Simple	1
Player Lives	Simple	1
Difficulty Levels	Simple	1

Total = 3 simple modifications (requirement met).