#include <stdio.h>
#include <stdbool.h>

#define N 4

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    //? Check this row on the left side
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    //? Check upper diagonal on the left side(row decreases and col decreases)
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
        {
            return false;
        }

    //? Check lower diagonal on the left side(row increases and col decreases)
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
        {
            return false;
        }

    return true;
}

void solveNQUtil(int board[N][N], int col)
{

    if (col == N)
    {
        printSolution(board);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            solveNQUtil(board, col + 1);

            board[i][col] = 0;
        }
    }
}

void solveNQ()
{
    int board[N][N] = {0};

    solveNQUtil(board, 0);
}

int main()
{
    solveNQ();
    return 0;
}
