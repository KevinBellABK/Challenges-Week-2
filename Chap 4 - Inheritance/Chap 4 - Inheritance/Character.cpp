#include "Character.h"

	Character::Character(float health, int x, int y)
		: m_Health(health)
		, m_pPoint(new Point(x,y))
		, m_isAlive(false)
	{

	}

	Character::~Character()
	{
		delete m_pPoint;
		m_pPoint = nullptr;
	}

	void Character::Move(int x, int y)
	{
		m_pPoint->x += x;
		m_pPoint->y += y;
	}

	void Character::TakeDamage(float damage)
	{
		if (m_isAlive)
		{
			m_Health -= damage;
			if (m_Health <= 0)
			{
				m_Health = 0;
				m_isAlive = false;
			}
		}
	}