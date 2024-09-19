#include <stdio.h>
#include <stdbool.h>

#define N 9

bool isSafe(char board[N][N], int row, int col, int number) {
    char numChar = (char)(number + '0');

    // Check the column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == numChar) {
            return false;
        }
    }

    // Check the row
    for (int j = 0; j < N; j++) {
        if (board[row][j] == numChar) {
            return false;
        }
    }

    // Check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == numChar) {
                return false;
            }
        }
    }

    return true;
}


bool solveSudokuHelper(char board[N][N], int row, int col) {
   
    if (row == N) {
        return true;
    }

    // Calculate the next row and column
    int nextRow = (col == N - 1) ? row + 1 : row;
    int nextCol = (col == N - 1) ? 0 : col + 1;

    // If the current cell is already filled, move to the next cell
    if (board[row][col] != '.') {
        return solveSudokuHelper(board, nextRow, nextCol);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (isSafe(board, row, col, i)) {
                board[row][col] = (char)(i + '0');  

                if (solveSudokuHelper(board, nextRow, nextCol)) {
                    return true;
                }
                board[row][col] = '.';  // Backtrack
            }
        }
    }

    return false;
}

void solveSudoku(char board[N][N]) {
    solveSudokuHelper(board, 0, 0);
}

void printBoard(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    char board[N][N] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    printf("Original Sudoku:\n");
    printBoard(board);

    solveSudoku(board);

    printf("\nSolved Sudoku:\n");
    printBoard(board);

    return 0;
}
