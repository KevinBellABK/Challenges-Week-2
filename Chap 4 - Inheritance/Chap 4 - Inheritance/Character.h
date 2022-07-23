#pragma once
#include "Point.h"
#include <iostream>

class Character
{
protected:
	float m_Health;
	bool m_isAlive;
	Point* m_pPoint;

public:
	Character(float health, int x, int y);

	virtual ~Character();

	virtual void Draw() = 0;

	void Move(int x, int y);

	void TakeDamage(float damage);
};

