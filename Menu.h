#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <iostream>






using namespace sf;
using namespace std;

const int W = 1200;
const int H = 700;



class Menu
{
private:
	Font font, font2;
	Text menu, title1, title2, titleAbout, title3;

public:
	void interact(RenderWindow& app);
	Menu();
	~Menu();
	

};