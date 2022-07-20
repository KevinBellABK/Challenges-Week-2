#include "Enemey.h"

class Enemey : public Character
{
public:
	void Draw() override
	{
		std::cout << "*" << std::endl;
	}
};