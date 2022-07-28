#pragma once
#include <iostream>
class Player
{
public:
	int m_X = -1;
	int m_Y = -1;
	std::string m_Name;

	Player()
		:m_Name("")
	{

	}

	Player(std::string name)
		:m_Name(name)
	{

	}

	virtual ~Player() {};

	virtual void selectPlace(__int8 board[3][3]) = 0;
};

