#pragma once
class Board
{
public:
	__int8 m_board[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };;

	//Board();

	void PrintBoard();

	__int8 WinCheck();
};

