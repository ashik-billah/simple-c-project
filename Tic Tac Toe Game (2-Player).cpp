#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char current_marker;
int current_player;

void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0; // No winner yet
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    cin >> current_marker;

    current_player = 1;
    int winner_player;

    drawBoard();

    for (int i = 0; i < 9; i++) {
        int slot;
        cout << "Player " << current_player << " (" << current_marker << "), enter your move (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid move! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        winner_player = winner();
        if (winner_player != 0) {
            cout << "Player " << winner_player << " wins! \n";
            return;
        }

        // Switch player
        current_player = (current_player == 1) ? 2 : 1;
        current_marker = (current_marker == 'X') ? 'O' : 'X';
    }

    cout << "It's a draw! 🤝\n";
}

int main() {
    game();
    return 0;
}

