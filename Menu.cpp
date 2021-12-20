#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Menu.h"
#include "Animation.h"
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::interact(RenderWindow& app)
{
	srand(time(0));
	app.setFramerateLimit(60);

	Texture menuTexture1,menuTexture2, menuBackground;
	menuBackground.setSmooth(true);
	menuTexture1.loadFromFile("images/button.png");
	menuTexture2.loadFromFile("images/button.png");
	menuBackground.loadFromFile("images/background.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menuBg(menuBackground);
	int menuNum = 0;

	if (!font.loadFromFile("Fonts/CricketInlineShaddow.ttf"))
	{
		cout << "No fonts here";
	}

	menu.setFont(font);
	menu.setFillColor(Color::Blue);
	menu.setString("Menu");
	menu.setCharacterSize(90);
	menu.setPosition(60, 30);

	if (!font2.loadFromFile("Fonts/Gecko_Personal_Use_Only.ttf"))
	{
		cout << "No fonts here";
	}

	title1.setFont(font2);
	title1.setFillColor(Color::Black);
	title1.setString("New game");
	title1.setCharacterSize(30);
	title1.setPosition(90, 210);

	if (!font2.loadFromFile("Fonts/Gecko_Personal_Use_Only.ttf"))
	{
		cout << "No fonts here";
	}

	if (!font2.loadFromFile("Fonts/Gecko_Personal_Use_Only.ttf"))
	{
		cout << "No fonts here";
	}

	title2.setFont(font2);
	title2.setFillColor(Color::Black);
	title2.setString("Exit");
	title2.setCharacterSize(30);
	title2.setPosition(130, 310);

	menu1.setPosition(60, 200);
	menu2.setPosition(60, 300);
	menuBg.setPosition(0, 0);

	menu1.setColor(Color::White);
	menu2.setColor(Color::White);
	menuNum = 0;
	app.clear();

	if (IntRect(60, 200, 200, 80).contains(Mouse::getPosition(app)))
	{
		menu1.setColor(Color::Blue);
		menuNum = 1;
	}
	
	if (IntRect(60, 300, 200, 80).contains(Mouse::getPosition(app)))
	{
		menu2.setColor(Color::Blue);
		menuNum = 2;
	}

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (menuNum == 1)
		{
			

		}

		if (menuNum == 2)
		{
			app.close();
		}
	}
	
		app.draw(menuBg);
		app.draw(menu1);
		app.draw(menu2);
		app.draw(menu);
		app.draw(title1);
		app.draw(title2);
		app.display();
}

