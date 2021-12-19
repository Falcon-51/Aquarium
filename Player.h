#pragma once
#include "Entity.h"
#include "Bubble.h"

class Player : public Entity
{
public:
    bool flow;
    Player();
    void update();
};