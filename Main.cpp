#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Menu.h"

using namespace sf;
using namespace std;

int main()
{
	setlocale(0, "rus");
    RenderWindow app(VideoMode(W, H), "Aquarium", Style::Close | Style::Titlebar);
    
    Menu menu;
    

    while (app.isOpen()) //Пока окно открыто
    {
        menu.interact(app);
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
        }
        
    }
	return 0;
}