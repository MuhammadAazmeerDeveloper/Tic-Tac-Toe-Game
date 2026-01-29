
#include <iostream>
#include <cstdlib>   // for system("cls")
using namespace std;

// Function to display the game board
void displayBoard(char board[3][3]) {
    cout << "\n Tic Tac Toe Board\n\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        if (i < 2)
            cout << "\n---|---|---\n";
    }
    cout << "\n\n";
}

// Function to take input from the player
void takeInput(char board[3][3], char player) {
    int row, col;

    while (true) {
        cout << "Player (" << player << ") enter row and column (1-3): ";
        cin >> row >> col;

        // Check valid range
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "? Invalid range! Please enter values between 1 and 3.\n";
        }
        // Check if cell is already occupied
        else if (board[row - 1][col - 1] != ' ') {
            cout << "? Cell already occupied! Choose another.\n";
        }
        else {
            board[row - 1][col - 1] = player;
            break;
        }
    }
}

// Function to check winner
bool checkWinner(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check draw
bool isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char choice;

    do {
        char board[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };

        char currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            system("cls"); // Clear screen (Windows)
            displayBoard(board);

            takeInput(board, currentPlayer);

            // Check win
            if (checkWinner(board, currentPlayer)) {
                system("cls");
                displayBoard(board);
                cout << "?? Player (" << currentPlayer << ") wins!\n";
                gameOver = true;
            }
            // Check draw
            else if (isDraw(board)) {
                system("cls");
                displayBoard(board);
                cout << "?? Game is a draw!\n";
                gameOver = true;
            }
            else {
                // Switch player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThanks for playing Tic Tac Toe!\n";
    return 0;
}
