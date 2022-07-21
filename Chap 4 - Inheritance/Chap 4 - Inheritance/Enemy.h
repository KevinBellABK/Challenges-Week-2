#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(float health, int x, int y);

	void Draw() override;
};

