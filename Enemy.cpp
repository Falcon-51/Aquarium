#include "Enemy.h"

Enemy::Enemy()
{

    dx = rand() % 4;
    if (dx == 0)
    {
        dx -= 1;
    }
    else
    {
        dx *= -1;
    }
    
    name = "Enemy";
}

void Enemy::update()
{
    x += dx;


    if (x > W) x = 0;  if (x < 0) x = W;
    if (y > H) y = 0;  if (y < 0) y = H;
}
