#include "Player.h"

Player::Player()
{
	name = "Player";
}

void Player::update()
{
    if (flow)
    {
        dx += cos(angle * deg) * 0.3;
        dy += sin(angle * deg) * 0.3;
    }
    else
    {
        dx *= 0.99;
        dy *= 0.99;
    }

    int maxSpeed = 2;
    float speed = sqrt(dx * dx + dy * dy);
    if (speed > maxSpeed)
    {   
        dx *= maxSpeed / speed;
        dy *= maxSpeed / speed;
    }

    x += dx;
    y += dy;
}
