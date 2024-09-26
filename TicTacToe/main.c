#include <stdio.h>
#include <stdbool.h>

// Function to display the Tic Tac Toe board
void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over (win or draw)
bool isGameOver(char board[3][3]) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true; // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true; // Column win
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true; // Diagonal win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true; // Diagonal win

    // Check for a draw (all cells filled)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false; // Game still ongoing
        }
    }
    return true; // Draw
}

// Function to validate user input
bool isValidMove(char board[3][3], int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    return (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O');
}

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int currentPlayer = 1; // Player 1 starts (you can change this)

    while (!isGameOver(board)) {
        displayBoard(board);

        int choice;
        printf("Player %d, choose a position (1-9): ", currentPlayer);
        scanf("%d", &choice);

        if (!isValidMove(board, choice)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Update the board based on the player's choice
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';

        // Toggle players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    displayBoard(board);
    printf("Game over!\n");

    return 0;
}

