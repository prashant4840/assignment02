// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <termios.h>
// #include <time.h>
// #include <fcntl.h>

// // ----------------------------------------------------
// // POSIX implementations of kbhit() and getch()
// // ----------------------------------------------------

// int kbhit(void) {
//     struct termios oldt, newt;
//     int ch;
//     int oldf;

//     tcgetattr(STDIN_FILENO, &oldt);        // get terminal properties
//     newt = oldt;
//     newt.c_lflag &= ~(ICANON | ECHO);      // turn off line buffering & echo
//     tcsetattr(STDIN_FILENO, TCSANOW, &newt);

//     oldf = fcntl(STDIN_FILENO, F_GETFL, 0); 
//     fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

//     ch = getchar();  // read

//     tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // restore settings
//     fcntl(STDIN_FILENO, F_SETFL, oldf);

//     if (ch != EOF) {
//         ungetc(ch, stdin);  // put character back
//         return 1;
//     }

//     return 0;
// }

// int getch(void) {
//     struct termios oldt, newt;
//     int ch;

//     tcgetattr(STDIN_FILENO, &oldt); 
//     newt = oldt;
//     newt.c_lflag &= ~(ICANON | ECHO);  // disable canonical mode
//     tcsetattr(STDIN_FILENO, TCSANOW, &newt);

//     ch = getchar();  

//     tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
//     return ch;
// }

// // ----------------------------------------------------
// // MAIN GAME
// // ----------------------------------------------------

// int main() {
//     srand(time(0));

//     int x = 1;              // player position (0 to 2)
//     int step = 0;           // obstacle vertical movement
//     int obstaclePos = rand() % 3;   // 0,1,2 lane

//     while (1) {

//         // ---- INPUT ----
//         if (kbhit()) {
//             char ch = getch();

//             if ((ch == 'a' || ch == 'A') && x > 0)
//                 x--;

//             if ((ch == 'd' || ch == 'D') && x < 2)
//                 x++;
//         }

//         // ---- CLEAR SCREEN (macOS compatible) ----
//         printf("\033[2J\033[1;1H");  // ANSI escape code

//         // ---- DRAW ----
//         printf("|--- --- ---|\n");

//         for (int i = 0; i < 10; i++) {
//             if (i == step) {

//                 if (obstaclePos == 0)
//                     printf("| #        |\n");

//                 else if (obstaclePos == 1)
//                     printf("|     #    |\n");

//                 else if (obstaclePos == 2)
//                     printf("|        # |\n");

//             } 
//             else {
//                 printf("|           |\n");
//             }
//         }

//         // ---- PLAYER ----
//         if (x == 0)
//             printf("| A        |\n");
//         else if (x == 1)
//             printf("|     A    |\n");
//         else if (x == 2)
//             printf("|        A |\n");

//         // ---- COLLISION ----
//         if (step == 10 && x == obstaclePos) {
//             printf("\nGAME OVER!\n");
//             break;
//         }

//         usleep(120000);  // Sleep for 120 ms

//         // Move obstacle down
//         step++;

//         // Reset when reaches bottom
//         if (step > 10) {
//             step = 0;
//             obstaclePos = rand() % 3; // new lane
//         }
//     }

//     return 0;
// }






#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>      // Windows: kbhit(), getch()
#include <windows.h>    // Sleep()

// ----------------------------------------------------
// MAIN GAME (Windows Compatible)
// ----------------------------------------------------

int main() {
    srand((unsigned)time(NULL));

    int x = 1;                     // player lane (0–2)
    int step = 0;                  // falling obstacle row
    int obstaclePos = rand() % 3;  // random 0–2 lane

    while (1) {

        // ------- INPUT -------
        if (_kbhit()) {
            char ch = _getch();

            if ((ch == 'a' || ch == 'A') && x > 0)
                x--;

            if ((ch == 'd' || ch == 'D') && x < 2)
                x++;
        }

        // ------- CLEAR SCREEN -------
        system("cls");   // Windows screen clear

        // ------- DRAW -------
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++) {

            if (i == step) {
                if (obstaclePos == 0)
                    printf("| #        |\n");
                else if (obstaclePos == 1)
                    printf("|     #    |\n");
                else
                    printf("|        # |\n");
            }
            else {
                printf("|           |\n");
            }
        }

        // ------- PLAYER -------
        if (x == 0)
            printf("| A        |\n");
        else if (x == 1)
            printf("|     A    |\n");
        else
            printf("|        A |\n");

        // ------- COLLISION -------
        if (step == 10 && x == obstaclePos) {
            printf("\nGAME OVER!\n");
            break;
        }

        // ------- FRAME DELAY (120 ms) -------
        Sleep(120);

        // Move obstacle down
        step++;

        // Reset when reaches bottom
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3;
        }
    }

    return 0;
}