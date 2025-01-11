#include <stdio.h>
#include <stdbool.h>

#define SIZE 19

char board[SIZE][SIZE];

bool check_winner(char player) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != player) continue;

            // Check horizontally
            if (j <= SIZE - 5) {
                bool win = true;
                for (int k = 0; k < 5; k++) {
                    if (board[i][j + k] != player) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }

            // Check vertically
            if (i <= SIZE - 5) {
                bool win = true;
                for (int k = 0; k < 5; k++) {
                    if (board[i + k][j] != player) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }

            // Check diagonally (top-left to bottom-right)
            if (i <= SIZE - 5 && j <= SIZE - 5) {
                bool win = true;
                for (int k = 0; k < 5; k++) {
                    if (board[i + k][j + k] != player) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }

            // Check diagonally (top-right to bottom-left)
            if (i <= SIZE - 5 && j >= 4) {
                bool win = true;
                for (int k = 0; k < 5; k++) {
                    if (board[i + k][j - k] != player) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    if (check_winner('O')) {
        printf("White\n");
    } else if (check_winner('X')) {
        printf("Black\n");
    } else {
        printf("No winner\n");
    }

    return 0;
}
