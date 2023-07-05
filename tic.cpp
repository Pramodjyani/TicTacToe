#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        currentPlayer = 'X';
        InitializeBoard();
    }

    void Play() {
        int row, col;
        bool gameOver = false;

        while (!gameOver) {
            DrawBoard();
            cout << "Player " << currentPlayer << ", enter your move (row column): ";
            cin >> row >> col;

            if (IsValidMove(row, col)) {
                MakeMove(row, col);

                if (IsWin()) {
                    DrawBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                } else if (IsBoardFull()) {
                    DrawBoard();
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    SwitchPlayer();
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }

private:
    void InitializeBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '-';
            }
        }
    }

    void DrawBoard() {
        cout << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool IsValidMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            return false;
        }
        if (board[row][col] != '-') {
            return false;
        }
        return true;
    }

    void MakeMove(int row, int col) {
        board[row][col] = currentPlayer;
    }

    bool IsWin() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }

        return false;
    }

    bool IsBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    return false;
                }
            }
        }
        return true;
    }

    void SwitchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
};

int main() {
    TicTacToe game;
    game.Play();
}