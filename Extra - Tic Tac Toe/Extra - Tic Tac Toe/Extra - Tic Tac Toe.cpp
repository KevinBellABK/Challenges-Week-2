#include <iostream>
#include <Windows.h>
#include "Board.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
using namespace std;

int PlayGame(int playerCnt, string p1Name, string p2Name)
{
    srand(time(0));
    int p1Num = rand(), p2Num = rand(), turn = 0, winner = -1;
    string turnName;
    Board playBoard;
    Player* players[2];
    if (p1Name._Equal("San") && playerCnt == 0)  players[0] = new AIPlayer(p1Name); else players[0] = new HumanPlayer(p1Name);
    if (p2Name._Equal("Nano")) players[1] = new AIPlayer(); else players[1] = new HumanPlayer(p2Name);
    if (p1Num < p2Num)
        turn = 1;

    do {
        turn = turn == 0 ? 1 : 0;
        system("cls");
        cout << players[turn]->m_Name << "'s Turn!" << endl;
        playBoard.PrintBoard();
        players[turn]->selectPlace(playBoard.m_board);
        
        playBoard.m_board[players[turn]->m_X][players[turn]->m_Y] = turn + 1;
        winner = playBoard.WinCheck();
    } while (winner == 0);

    system("cls");
    playBoard.PrintBoard();
    if (winner == -1)
        cout << "Stalemate!" << endl;
    else
        cout << "Congrats " << players[turn]->m_Name << ". You won!!" << endl;
    return winner;
}

int main()
{
    int playerNum = 0, winner, p1Wins = 0, p2Wins = 0;
    
    string p1Name = "", p2Name = "";
    do {
        cout << "How many players (1 or 2): ";
        cin >> playerNum;

        if (playerNum != 1 && playerNum != 2 && playerNum != 0)
            cout << "!INVALID NUMBER OF PLAYERS!" << endl;
        else if (playerNum == 1)
            p2Name = "Nano";
        else if (playerNum == 0)
        {
            p1Name = "San";
            p2Name = "Nano";
        }

    } while (playerNum != 1 && playerNum != 2 && playerNum != 0);

    if (playerNum == 1)
    {
        cout << "Player Name: ";
        cin >> p1Name;
    }
    else if (playerNum == 2)
    {
        cout << "Player 1 Name: ";
        cin >> p1Name;
        cout << "Player 2 Name: ";
        cin >> p2Name;
    }

    char playAgain = 'N';

    do {
        winner = PlayGame(playerNum, p1Name, p2Name);

        if (winner == 1)
            p1Wins++;
        else if (winner == 2)
            p2Wins++;
        
        cout << p1Name << ": " << p1Wins << "  ||  " << p2Name << ": " << p2Wins << endl << "Play Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
}