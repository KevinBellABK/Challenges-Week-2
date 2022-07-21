#include <iostream>
#include "Player.h"
#include "Enemy.h"

int main()
{
    Player* p = new Player(100.0f, 1, 2);
    Enemy* e = new Enemy(100.0f, 1, 2);

    p->Draw();
    e->Draw();
}
