#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int board[3][3] = {0};
    int x, y, winner = 0;
    int player;

    srand(time(NULL));

    printf("Who moves first? (0-you, 1-pc): ");
    scanf("%d", &player);

    printf("~~~TIC TAC TOE~~~\n");
    while (1) {
        printf("___________\n");
        for (int i = 0; i < 3; i++) {
            printf(" %c | %c | %c \n",
                   (board[i][0] == 0) ? '_' : (board[i][0] == 1) ? 'O' : 'X',
                   (board[i][1] == 0) ? '_' : (board[i][1] == 1) ? 'O' : 'X',
                   (board[i][2] == 0) ? '_' : (board[i][2] == 1) ? 'O' : 'X');
            if (i < 2) {
                printf("___|___|___\n");

            }
        }
        printf("___________\n");
        // checking for the winner
        winner = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                winner = board[i][0];
                break;
            }
        }
        if (winner == 0) {
            for (int j=0; j < 3; j++) {
                if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                    winner = board[0][j];
                    break;
                }
            }
        }
        if (winner==0) {
            if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                winner = board[0][0];
            }
            if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                winner = board[0][2];
            }
        }

        if (winner!=0){
            break;
        }

        if (player==0) {
            printf("Your move (x,y): ");
            scanf("%d,%d", &x, &y);//user input
            if (x<1 || x>3 || y<1 || y>3 || board[x-1][y-1] != 0) {
                printf("The position [%i][%i] is not empty, give another coordinate.\n", x, y);
                continue;
            }
            board[x-1][y-1] = 1;
            printf("User chosen position [%i][%i]\n", x, y);
        }

        winner = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                winner = board[i][0];
                break;
            }
        }
        if (winner == 0) {
            for (int j = 0; j < 3; j++) {
                if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                    winner = board[0][j]; // Return the winner
                    break;
                }
            }
        }
        if (winner == 0) {
            if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                winner = board[0][0];
            }
            if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                winner = board[0][2];
            }
        }

        if (winner != 0) break;

        //computer's move
        if (player == 1) {
            do {
                x = rand() % 3;
                y = rand() % 3;
            } while (board[x][y] != 0);

            board[x][y] = 2;
            printf("The pc is making a move: [%i][%i]\n", x + 1, y + 1);
        }

        //checking if computer won or not
        winner = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                winner = board[i][0];
                break;
            }
        }
        if (winner == 0) {
            for (int j = 0; j < 3; j++) {
                if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                    winner = board[0][j];
                    break;
                }
            }
        }
        if (winner == 0) {
            if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                winner = board[0][0];
            }
            if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                winner = board[0][2];
            }
        }

        if (winner != 0){
            break;
        }

        player = !player;
    }

    // end of the game
    printf("~~~TIC TAC TOE~~~\n");
    printf("___________\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n",
               (board[i][0] == 0) ? '_' : (board[i][0] == 1) ? 'O' : 'X',
               (board[i][1] == 0) ? '_' : (board[i][1] == 1) ? 'O' : 'X',
               (board[i][2] == 0) ? '_' : (board[i][2] == 1) ? 'O' : 'X');
        if (i < 2) {
            printf("___|___|___\n");
        }
    }
    printf("___________\n");

    if (winner == 1) {
        printf("Game over. The winner - user.");
    } else if (winner == 2) {
        printf("Game over. The winner - PC.");
    } else {
        printf("Game over, the result is draw.");
    }
    return 0;
}