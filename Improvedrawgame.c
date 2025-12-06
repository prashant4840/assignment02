#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>     // Windows: kbhit(), getch()
#include <windows.h>   // Sleep()

// Clear screen (Windows)
void clearScreen() {
    system("cls");
}

int main() {
    srand((unsigned)time(NULL));

    int x = 1;                      // Player lane (0–2)
    int step = 0;                  // Falling obstacle row
    int obstaclePos = rand() % 3;  // 0, 1, or 2

    int score = 0;
    int lives = 3;
    int speed = 120;               // Sleep in milliseconds

    while (1) {

        // INPUT
        if (_kbhit()) {
            char ch = _getch();

            if ((ch == 'a' || ch == 'A') && x > 0) x--;
            if ((ch == 'd' || ch == 'D') && x < 2) x++;
        }

        // CLEAR SCREEN
        clearScreen();

        // HUD
        printf("Score: %d   Lives: %d\n", score, lives);
        printf("|--- --- ---|\n");

        // GAME FIELD
        for (int i = 0; i < 10; i++) {
            if (i == step) {

                if (obstaclePos == 0)
                    printf("| #        |\n");
                else if (obstaclePos == 1)
                    printf("|     #    |\n");
                else
                    printf("|        # |\n");

            } else {
                printf("|           |\n");
            }
        }

        // PLAYER
        if (x == 0)
            printf("| A        |\n");
        else if (x == 1)
            printf("|     A    |\n");
        else
            printf("|        A |\n");

        // COLLISION CHECK
        if (step == 10) {
            if (x == obstaclePos) {
                lives--;
                if (lives == 0) {
                    printf("\nGAME OVER! Final Score: %d\n", score);
                    break;
                }
            } else {
                score++;
            }
        }

        // INCREASE DIFFICULTY
        if (score > 0 && score % 5 == 0 && speed > 50) {
            speed -= 5;
        }

        // FRAME DELAY (Windows)
        Sleep(speed);

        // MOVE OBSTACLE
        step++;

        // RESET OBSTACLE
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3;
        }
    }

    return 0;
}