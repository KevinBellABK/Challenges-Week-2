#include "Board.h"
#include <iostream>
#include <windows.h>

using namespace std;

void Board::PrintBoard()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int place = 1;
    for (int i = 0; i < 3; i++)
    {
        cout << "|";
        for (int j = 0; j < 3; j++)
        {
            cout << " ";
            if (m_board[i][j] == 0)
                cout << place << " |";
            else if (m_board[i][j] == 1)
            {
                SetConsoleTextAttribute(console, 12);
                cout << "X ";
                SetConsoleTextAttribute(console, 7);
                cout << "|";
            }
            else
            {
                SetConsoleTextAttribute(console, 10);
                cout << "O ";
                SetConsoleTextAttribute(console, 7);
                cout << "|";
            }
            place++;
        }
        cout << endl;
    }
    cout << endl;
}

__int8 Board::WinCheck()
{
    bool wholeBoardFull = false;
    int boardCheck = m_board[0][0] * m_board[0][1] * m_board[0][2];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;
    int wholeBoardCheck = boardCheck;

    boardCheck = m_board[1][0] * m_board[1][1] * m_board[1][2];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;
    wholeBoardCheck *= boardCheck;

    boardCheck = m_board[2][0] * m_board[2][1] * m_board[2][2];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;
    wholeBoardCheck *= boardCheck;
    if (wholeBoardCheck != 0)
        wholeBoardFull = true;

    boardCheck = m_board[0][0] * m_board[1][0] * m_board[2][0];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;

    boardCheck = m_board[0][1] * m_board[1][1] * m_board[2][1];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;

    boardCheck = m_board[0][2] * m_board[1][2] * m_board[2][2];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;

    boardCheck = m_board[0][0] * m_board[1][1] * m_board[2][2];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;

    boardCheck = m_board[0][2] * m_board[1][1] * m_board[2][0];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;
    else if (wholeBoardFull)
        return -1;
    return 0;
}
