#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <fcntl.h>

// ----------------------------------------------------
// POSIX kbhit() and getch()
// ----------------------------------------------------

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int getch(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// ----------------------------------------------------
// MAIN GAME
// ----------------------------------------------------

int main() {
    srand(time(0));

    int x = 1;                     // player lane (0–2)
    int step = 0;                  // falling obstacle row
    int obstaclePos = rand() % 3;  // 0, 1, or 2

    int score = 0;                 // NEW FEATURE
    int lives = 3;                 // NEW FEATURE
    int speed = 120000;            // NEW FEATURE (difficulty adjuster)

    while (1) {

        // INPUT
        if (kbhit()) {
            char ch = getch();

            if ((ch == 'a' || ch == 'A') && x > 0) x--;
            if ((ch == 'd' || ch == 'D') && x < 2) x++;
        }

        // CLEAR SCREEN
        printf("\033[2J\033[1;1H");

        // HUD DISPLAY
        printf("Score: %d   Lives: %d\n", score, lives);
        printf("|--- --- ---|\n");

        // DRAW GAME FIELD
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

        // DRAW PLAYER
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
                score++;   // NEW: gain score for dodging
            }
        }

        // DIFFICULTY INCREASE EVERY 5 POINTS
        if (score > 0 && score % 5 == 0 && speed > 50000) {
            speed -= 5000;
        }

        // FRAME DELAY
        usleep(speed);

        // MOVE OBSTACLE DOWN
        step++;

        // RESET OBSTACLE
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3;
        }
    }

    return 0;
}