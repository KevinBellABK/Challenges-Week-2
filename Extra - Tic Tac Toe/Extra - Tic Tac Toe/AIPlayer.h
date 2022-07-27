#pragma once
#include "Player.h"

class AIPlayer : public Player
{
public:
    AIPlayer()
        :Player("Nano")
    {

    }

    AIPlayer(std::string name)
        :Player(name)
    {

    }

    void selectPlace(__int8 board[3][3]);
};