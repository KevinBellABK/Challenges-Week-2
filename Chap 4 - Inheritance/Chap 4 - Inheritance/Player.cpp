#include "Player.h"

	Player::Player(float health, int x, int y)
		: Character(health, x, y)
		, m_HasKey(false)
	{

	}

	void Player::Draw()
	{
		std::cout << "@";
	}

	void Player::UseHealth(float health)
	{
		m_Health += health;
		if (!m_isAlive)
		{
			m_isAlive = true;
		}
	}

	void Player::PickupKey()
	{
		m_HasKey = true;
	}