#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Menu.h"

class Animation
{
public:
    float Frame, speed;
    Sprite sprite;
    vector<IntRect> frames;

    Animation(){}
    Animation(Texture& t, int x, int y, int w, int h, int count, float Speed);
    void update();
    bool isEnd();
};
