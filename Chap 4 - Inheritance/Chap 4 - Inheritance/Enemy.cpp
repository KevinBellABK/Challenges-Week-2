#include "Enemy.h"

	Enemy::Enemy(float health, int x, int y)
	: Character(health, x, y)
	{
	}

	void Enemy::Draw()
	{
		std::cout << "*" << std::endl;
	}