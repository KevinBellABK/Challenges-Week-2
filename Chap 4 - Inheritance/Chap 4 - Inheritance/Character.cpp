#include "Character.h"

class Character
{
protected:
	float m_Health;
	bool m_isAlive;
	Point* m_pPoint;

public:
	Character(float health, int x, int y)
		: m_Health(health)
		, m_pPoint(new Point(x,y))
		, m_isAlive(false)
	{

	}

	~Character()
	{
		delete m_pPoint;
		m_pPoint = nullptr;
	}

	virtual void Draw() = 0;

	void Move(int x, int y)
	{
		m_pPoint->x += x;
		m_pPoint->y += y;
	}

	void TakeDamage(float damage)
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
};