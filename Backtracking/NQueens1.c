#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 4

bool isSafe(int row, int col, char board[N][N])
{
    //? Check horizontal line (left and right)
    for (int j = 0; j < N; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    //? Check vertical line (up and down)
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    //? Check upper left diagonal
    int r = row;
    for (int c = col; c >= 0 && r >= 0; c--, r--)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }

    //? Check upper right diagonal
    r = row;
    for (int c = col; c < N && r >= 0; r--, c++)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }

    //? Check lower left diagonal
    r = row;
    for (int c = col; c >= 0 && r < N; r++, c--)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }

    //? Check lower right diagonal
    r = row;
    for (int c = col; c < N && r < N; r++, c++)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void printBoard(char board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solveNQueensHelper(char board[N][N], int col)
{

    if (col == N)
    {
        printBoard(board);
        return;
    }

    for (int row = 0; row < N; row++)
    {
        if (isSafe(row, col, board))
        {
            board[row][col] = 'Q';

            solveNQueensHelper(board, col + 1);

            board[row][col] = '.';
        }
    }
}

    void solveNQueens()
    {
        char board[N][N];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                board[i][j] = '.';
            }
        }

        solveNQueensHelper(board, 0);
    }

    int main()
    {
        solveNQueens();
        return 0;
    }
