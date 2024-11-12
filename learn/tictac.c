#include <stdio.h>

#define SIZE 3

void printGrid(char a[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", a[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE; k++) {
                printf("----");
                if (k < SIZE - 1) printf("+");
            }
            printf("\n");
        }
    }
}

int selection(char a[SIZE][SIZE], char player) {
    int pos;
    printf("Player %c, input where to place your mark (1-9): ", player);
    scanf("%d", &pos);
    
    
    int row = (pos - 1) / SIZE;
    int col = (pos - 1) % SIZE;

    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && a[row][col] == ' ') {
        a[row][col] = player;
        return 1; 
    } else {
        printf("Invalid position! Please try again.\n");
        return 0; 
    }
}

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int turn = 0;
    char players[] = {'X', 'O'};
    
    while (1) {
        printGrid(grid);
        if (selection(grid, players[turn % 2])) {
            turn++;
        }

        
        if (turn == SIZE * SIZE) {
            printf("It's a draw!\n");
            break;
        }
    }

    printGrid(grid);
    return 0;
}
