#include "Bubble.h"

Bubble::Bubble()
{
	name = "Bubble";
}

void Bubble::update()
{
    dx = cos(angle * deg) * 4;
    dy = sin(angle * deg) * 4;
    x += dx;
    y += dy;

    if (x > W || x<0 || y>H || y < 0) life = 0;
}
