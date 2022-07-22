#include <iostream>
using namespace std;

__int8 WinCheck(__int8 board[3][3])
{ 
    int boardCheck = board[0][0] * board[0][1] * board[0][2];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;
    int wholeBoardCheck = boardCheck;

    boardCheck = board[1][0] * board[1][1] * board[1][2];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;
    wholeBoardCheck *= boardCheck;

    boardCheck = board[2][0] * board[2][1] * board[2][2];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;
    wholeBoardCheck *= boardCheck;
    if (wholeBoardCheck != 0)
        return -1;

    boardCheck = board[0][0] * board[1][0] * board[2][0];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;

    boardCheck = board[0][1] * board[1][1] * board[2][1];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;

    boardCheck = board[0][2] * board[1][2] * board[2][2];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;

    boardCheck = board[0][0] * board[1][1] * board[2][2];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;

    boardCheck = board[0][2] * board[1][1] * board[2][0];
    if (boardCheck == 1)
        return 1;
    else if (boardCheck == 8)
        return 2;
    return 0;
}

void PrintBoard(__int8 board[3][3])
{
    int place = 1;
    for (int i = 0; i < 3; i++)
    {
        cout << "|";
        for (int j = 0; j < 3; j++)
        {
            cout << " ";
            if (board[i][j] == 0)
                cout << place << " |";
            else if (board[i][j] == 1)
                cout << "X |";
            else
                cout << "O |";
            place++;
        }
        cout << endl;
    }
    cout << endl;
}

void selectPlace(int selection, __int8 board[3][3], int& x, int& y)
{
    int place = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            place++;
            if (selection == place)
            {
                if (board[i][j] != 0)
                {
                    x = -1; y = -1;
                }
                else
                {
                    x = i; y = j;
                }    
            }
        }
    }
}

void Nano(_int8 board[3][3], int& x, int& y)
{
    __int8 viableBoard[3][3] = {};
    int viableMoves = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 1)
                viableBoard[i][j] = 3;
            else if (board[i][j] == 0)
            {
                viableBoard[i][j] = -1;
                viableMoves++;
            }
            else
                viableBoard[i][j] = 2;
        }
    }

    //0 == Going for Win, 1 == Blocking Win, 2 == Next to O, 3 == Random
    for (int k = 0; k < 4; k++)
    {
        int cnt = 1, move = 0;
        if (k == 3)
        {
            srand(time(0));
            move = rand() % viableMoves + 1;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (viableBoard[i][j] != -1)
                    continue;

                if (k != 3)
                {
                    int left = -1, right = -1, down = -1, up = -1, sides = -1, lAcross = -1, rAcross = -1, topBottom = -1;
                    if (i == 0)
                    {
                        down = viableBoard[i + 1][j] + board[i + 2][j];
                        //Top
                        if (j == 0)
                        {
                            //Left
                            right = viableBoard[i][j + 1] + board[i][j + 2];
                            lAcross = viableBoard[i + 1][j + 1] + board[i + 2][j + 2];
                        }
                        else if (j == 2)
                        {
                            //Right
                            left = viableBoard[i][j - 1] + board[i][j - 2];
                            rAcross = viableBoard[i + 1][j - 1] + board[i + 2][j - 2];
                        }
                        else
                        {
                            //Middle
                            sides = viableBoard[i][j - 1] + viableBoard[i][j + 1];

                        }
                    }
                    else if (i == 2)
                    {
                        topBottom = viableBoard[i - 1][j] + viableBoard[i + 1][j];
                        //Middle
                        if (j == 0)
                        {
                            //Left
                            right = viableBoard[i][j + 1] + board[i][j + 2];

                        }
                        else if (j == 2)
                        {
                            //Right
                            left = viableBoard[i][j - 1] + board[i][j - 2];
                        }
                        else
                        {
                            //Middle
                            sides = viableBoard[i][j - 1] + viableBoard[i][j + 1];
                            lAcross = viableBoard[i - 1][j - 1] + board[i + 1][j + 1];
                            rAcross = viableBoard[i + 1][j - 1] + board[i - 1][j + 1];
                        }
                    }
                    else
                    {
                        up = viableBoard[i + 1][j] + viableBoard[i + 2][j];
                        //Bottom
                        if (j == 0)
                        {
                            //Left
                            right = viableBoard[i][j + 1] + board[i][j + 2];
                            lAcross = viableBoard[i - 1][j + 1] + board[i - 2][j + 2];
                        }
                        else if (j == 2)
                        {
                            //Right
                            left = viableBoard[i][j - 1] + board[i][j - 2];
                            rAcross = viableBoard[i - 1][j - 1] + board[i - 2][j - 2];
                        }
                        else
                        {
                            //Middle
                            sides = viableBoard[i][j - 1] + viableBoard[i][j + 1];
                        }
                    }

                    if (k == 0)
                    {
                        if (down == 4 || right == 4 || left == 4 || sides == 4 || up == 4 || lAcross == 4 || rAcross == 4 || topBottom == 4)
                        {
                            x = i;
                            y = j;
                            return;
                        }
                    }
                    else if (k == 1)
                    {
                        if (down == 6 || right == 6 || left == 6 || sides == 6 || up == 6 || lAcross == 6 || rAcross == 6 || topBottom == 6)
                        {
                            x = i;
                            y = j;
                            return;
                        }
                    }
                    else if (k == 2)
                    {
                        if (down == 2 || right == 2 || left == 2 || sides == 2 || up == 2 || lAcross == 2 || rAcross == 2 || topBottom == 2)
                        {
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else
                {
                    if (cnt == move)
                    {
                        x = i;
                        y = j;
                        return;
                    }
                    else
                    {
                        cnt++;
                    }
                }
            }
        }
    }

}

void PlayGame(string p1Name, string p2Name)
{
    __int8 board[3][3] = { {0,0,0}, 
                           {0,0,0}, 
                           {0,0,0} };

    int p1Num = rand(), p2Num = rand(), turn = 1, winner = 0;
    if (p1Num < p2Num)
        turn = 2;

    do {
        string turnName = turn == 1 ? p1Name : p2Name;
        cout << turnName << "'s Turn!" << endl;
        PrintBoard(board);
        int x = -1, y = -1;

        if (turnName._Equal("Nano"))
        {
            Nano(board, x, y);
        }
        else
        {
            do {
                cout << "Pick a Place: ";
                int selection;
                cin >> selection;
                selectPlace(selection, board, x, y);
                if (x == -1)
                    cout << "!INVALID ENTRY!" << endl;
            } while (x == -1);
        }
        board[x][y] = turn;
        winner = WinCheck(board);
        
        if (turn == 1)
            turn = 2;
        else
            turn = 1;

    } while (winner == 0);

    PrintBoard(board);
    if (winner == -1)
        cout << "Stalemate!" << endl;
    else
    {
        string winnerName = winner == 1 ? p1Name : p2Name;
        cout << "Congrats " << winnerName << ". You won!!" << endl;
    }
}

int main()
{
    int playerNum = 0;
    
    string p1Name = "", p2Name = "";
    do {
        cout << "How many players (1 or 2): ";
        cin >> playerNum;

        if (playerNum != 1 && playerNum != 2)
            cout << "!INVALID NUMBER OF PLAYERS!" << endl;
        else if (playerNum == 1)
            p2Name = "Nano";

    } while (playerNum != 1 && playerNum != 2);

    if (playerNum == 1)
    {
        cout << "Player Name: ";
        cin >> p1Name;
    }
    else
    {
        cout << "Player 1 Name: ";
        cin >> p1Name;
        cout << "Player 2 Name: ";
        cin >> p2Name;
    }

    PlayGame(p1Name, p2Name);

}