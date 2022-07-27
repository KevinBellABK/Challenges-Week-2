#pragma once
#include "Player.h"

class HumanPlayer : public Player
{

public:
	HumanPlayer(std::string name);

	void selectPlace(__int8 board[3][3]) override;
};

