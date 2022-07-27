#include "HumanPlayer.h"
#include <iostream>

int selectX[] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
int selectY[] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };

HumanPlayer::HumanPlayer(std::string name)
    :Player(name)
{
}


void HumanPlayer::selectPlace(__int8 board[3][3])
{
    
    
    do {
        std::cout << "Pick a Place: ";
        int select;
        std::cin >> select;

        /*
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
                        break;
                    }
                    else
                    {
                        x = i; y = j;
                    }
                }
            }
            if (selection == place)
                break;
        }
        */
        if (board[selectX[select - 1]][selectY[select - 1]] != 0 || select > 9 || select < 0)
            m_X = -1;
        else
        {
            m_X = selectX[select - 1];
            m_Y = selectY[select - 1];
        }

        if (m_X == -1)
            std::cout << "!INVALID ENTRY!" << std::endl;
    } while (m_X == -1);
}
