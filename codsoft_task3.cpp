// codsoft_task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <windows.h>
using namespace std;

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void drawBoard()
{
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        if (i < 2)
            cout << "\n\t--|---|--\n";
    }
    cout << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

bool checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;

    return true;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

int main()
{
    char playAgain = 'Y';
    while (playAgain == 'Y' || playAgain == 'y')
    {
        int player = 0;
        while (true)
        {
            drawBoard();
            int x, y;
            cout << "Player " << player + 1 << ", enter your move (row and column): ";
            cin >> x >> y;
            x--;
            y--;

            if (board[x][y] != ' ')
            {
                cout << "Invalid move, try again." << endl;
                Sleep(2000);
                continue;
            }

            board[x][y] = (player == 0) ? 'X' : 'O';

            if (checkWin())
            {
                cout << "Player " << player + 1 << " wins!" << endl;
                break;
            }

            if (checkDraw())
            {
                cout << "The game is a draw." << endl;
                break;
            }
            player = !player;
        }
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        resetBoard();
    }
    return 0;
}
