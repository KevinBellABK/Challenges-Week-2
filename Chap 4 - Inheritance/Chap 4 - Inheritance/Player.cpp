#include "Player.h"


class Player : public Character
{
	bool m_HasKey;

public:
	Player(float health, int x, int y)
		: Character(health, x, y)
		, m_HasKey(false)
	{

	}

	void Draw() override
	{
		std::cout << "@";
	}

	void UseHealth(float health)
	{
		m_Health += health;
		if (!m_isAlive)
		{
			m_isAlive = true;
		}
	}

	void PickupKey()
	{
		m_HasKey = true;
	}

};