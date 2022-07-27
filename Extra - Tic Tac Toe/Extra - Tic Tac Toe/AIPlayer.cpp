#include "AIPlayer.h"

void AIPlayer::selectPlace(__int8 board[3][3])
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
                        down = viableBoard[i + 1][j] + viableBoard[i + 2][j];
                        //Top
                        if (j == 0)
                        {
                            //Left
                            right = viableBoard[i][j + 1] + viableBoard[i][j + 2];
                            lAcross = viableBoard[i + 1][j + 1] + viableBoard[i + 2][j + 2];
                        }
                        else if (j == 2)
                        {
                            //Right
                            left = viableBoard[i][j - 1] + viableBoard[i][j - 2];
                            rAcross = viableBoard[i + 1][j - 1] + viableBoard[i + 2][j - 2];
                        }
                        else
                        {
                            //Middle
                            sides = viableBoard[i][j - 1] + viableBoard[i][j + 1];

                        }
                    }
                    else if (i == 1)
                    {
                        topBottom = viableBoard[i - 1][j] + viableBoard[i + 1][j];
                        //Middle
                        if (j == 0)
                        {
                            //Left
                            right = viableBoard[i][j + 1] + viableBoard[i][j + 2];

                        }
                        else if (j == 2)
                        {
                            //Right
                            left = viableBoard[i][j - 1] + viableBoard[i][j - 2];
                        }
                        else
                        {
                            //Middle
                            sides = viableBoard[i][j - 1] + viableBoard[i][j + 1];
                            lAcross = viableBoard[i - 1][j - 1] + viableBoard[i + 1][j + 1];
                            rAcross = viableBoard[i + 1][j - 1] + viableBoard[i - 1][j + 1];
                        }
                    }
                    else
                    {
                        up = viableBoard[i - 1][j] + viableBoard[i - 2][j];
                        //Bottom
                        if (j == 0)
                        {
                            //Left
                            right = viableBoard[i][j + 1] + viableBoard[i][j + 2];
                            lAcross = viableBoard[i - 1][j + 1] + viableBoard[i - 2][j + 2];
                        }
                        else if (j == 2)
                        {
                            //Right
                            left = viableBoard[i][j - 1] + viableBoard[i][j - 2];
                            rAcross = viableBoard[i - 1][j - 1] + viableBoard[i - 2][j - 2];
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
                            m_X = i;
                            m_Y = j;
                            return;
                        }
                    }
                    else if (k == 1)
                    {
                        if (down == 6 || right == 6 || left == 6 || sides == 6 || up == 6 || lAcross == 6 || rAcross == 6 || topBottom == 6)
                        {
                            m_X = i;
                            m_Y = j;
                            return;
                        }
                    }
                    else if (k == 2)
                    {
                        if (down == 1 || right == 1 || left == 1 || sides == 1 || up == 1 || lAcross == 1 || rAcross == 1 || topBottom == 1)
                        {
                            m_X = i;
                            m_Y = j;
                            return;
                        }
                    }
                }
                else
                {
                    if (cnt == move)
                    {
                        m_X = i;
                        m_Y = j;
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
