// Task 4: 2-Player Tic-Tac-Toe using a 2D array
#include <iostream>
#include <limits>
using namespace std;

char board[3][3];

void resetBoard() {
    char c = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) board[i][j] = c++;
}

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << "  " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << " ---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true; // row
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true; // column
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;     // diagonal
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;     // anti-diagonal
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
    return true;
}

bool placeMove(int pos, char p) {
    if (pos < 1 || pos > 9) return false;
    int r = (pos - 1) / 3, c = (pos - 1) % 3;
    if (board[r][c] == 'X' || board[r][c] == 'O') return false;
    board[r][c] = p;
    return true;
}

int main() {
    char again;
    int scoreX = 0, scoreO = 0, draws = 0;
    cout << "=== TIC-TAC-TOE (2 Players) ===\n";
    do {
        resetBoard();
        char player = 'X';
        bool finished = false;
        while (!finished) {
            drawBoard();
            int pos;
            cout << "Player " << player << ", choose a cell (1-9): ";
            if (!(cin >> pos)) {
                if (cin.eof()) return 0;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "  Invalid input. Enter a number 1-9.\n";
                continue;
            }
            if (!placeMove(pos, player)) {
                cout << "  Invalid move or cell already taken. Try again.\n";
                continue;
            }
            if (checkWin(player)) {
                drawBoard();
                cout << "*** Player " << player << " wins! ***\n";
                (player == 'X') ? scoreX++ : scoreO++;
                finished = true;
            } else if (isDraw()) {
                drawBoard();
                cout << "*** It's a draw! ***\n";
                draws++;
                finished = true;
            } else {
                player = (player == 'X') ? 'O' : 'X';
            }
        }
        cout << "Score -> X: " << scoreX << " | O: " << scoreO << " | Draws: " << draws << "\n";
        cout << "Play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    cout << "Thanks for playing!\n";
    return 0;
}
