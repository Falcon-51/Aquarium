#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include "Menu.h"
#include "Animation.h"
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

bool isCollide(Entity* a, Entity* b)
{
    return (b->x - a->x) * (b->x - a->x) +
        (b->y - a->y) * (b->y - a->y) <
        (a->R + b->R) * (a->R + b->R);
}



int main()
{
	setlocale(0, "rus");
    RenderWindow app(VideoMode(W, H), "Aquarium", Style::Close | Style::Titlebar);
    srand(time(0));
    app.setFramerateLimit(60);
    Menu menu;
    Text score;
    Font font;
    int schet = 0;


    //Score
    if (!font.loadFromFile("Fonts/Gecko_Personal_Use_Only.ttf"))
    {
        cout << "No fonts here";
    }

    score.setFont(font);
    score.setFillColor(Color::Black);
    score.setCharacterSize(40);
    score.setPosition(60, 20);
    //End 



    Texture t1, t2, t3, t4, t5, t7, t8, t9;
    t1.loadFromFile("images/hero.png");
    t2.loadFromFile("images/background.jpg");
    t3.loadFromFile("images/explosions/bubble_boom.png");
    t4.loadFromFile("images/angry1.png");
    t5.loadFromFile("images/bubble.png");
    t7.loadFromFile("images/explosions/bubble_boom.png");
    t8.loadFromFile("images/angry2.png");
    t9.loadFromFile("images/angry3.png");

    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite background(t2);

    Animation sExplosion(t3, 0, 0, 256, 256, 24, 0.1);
    Animation sExplosion_fish(t7, 0, 0, 180, 180, 24, 0.1);

    Animation sAngry1(t4, 0, 0, 75, 75, 1, 0);
    Animation sAngry2(t8, 0, 0, 75, 75, 1, 0);
    Animation sAngry3(t9, 0, 0, 75, 75, 1, 0);

    Animation sBubble(t5, 0, 0, 20, 20, 1, 0);

    Animation sPlayer(t1, 0, 0, 90, 90, 1, 0);
    Animation sPlayer_go(t1, 0, 0, 90, 90, 1, 0);



    list<Entity*> entities;

    for (int i = 0; i < 3; i++)
    {
        Enemy* A = new Enemy();
        A->settings(sAngry1, rand() % W, rand() % H, 0, 32.5);
        entities.push_back(A);
    }

    for (int i = 0; i < 3; i++)
    {
        Enemy* A = new Enemy();
        A->settings(sAngry2, rand() % W, rand() % H, 0, 32.5);
        entities.push_back(A);
    }

    for (int i = 0; i < 3; i++)
    {
        Enemy* A = new Enemy();
        A->settings(sAngry3, rand() % W, rand() % H, 0, 32.5);
        entities.push_back(A);
    }

    Player* P = new Player();
    P->settings(sPlayer, 200, 350, 0, 45);
    entities.push_back(P);
    


    while (app.isOpen()) 
    {
        if ((IntRect(60, 200, 200, 80).contains(Mouse::getPosition(app))) && (Mouse::isButtonPressed(Mouse::Left)))
        {
            while (app.isOpen())
            {
                Event event;
                while (app.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                        app.close();

                    if (event.type == Event::KeyPressed)
                        if (event.key.code == Keyboard::Escape)
                        {
                            app.close();
                        }
                 
                    if (event.type == Event::KeyReleased)
                        if (event.key.code == Keyboard::Space)
                        {
                            Bubble* B = new Bubble();
                            B->settings(sBubble, P->x + 20, P->y, P->angle, 10);
                            entities.push_back(B);
                        }
                }

                if (Keyboard::isKeyPressed(Keyboard::Right))
                {
                    if (P->angle == 45)
                    {
                        P->angle += 0;
                    }
                    else
                    {
                        P->angle += 3;
                    }
                }

                if (Keyboard::isKeyPressed(Keyboard::Left))
                {
                    if (P->angle == -45)
                    {
                        P->angle += 0;
                    }
                    else
                    {
                        P->angle -= 3;
                    }
                }

                if (Keyboard::isKeyPressed(Keyboard::Up))
                {
                    P->flow = true;

                }
                else
                {
                    P->flow = false;
                    P->dx += -0.03;
                }

                for (auto a : entities)
                    for (auto b : entities)
                    {
                        if (a->name == "Enemy" && b->name == "Bubble")
                            if (isCollide(a, b))
                            {
                                a->life = false;
                                b->life = false;

                                Entity* e = new Entity();
                                e->settings(sExplosion, a->x, a->y);
                                e->name = "boom";
                                entities.push_back(e);
                                ++schet;
                               
                            }

                        if (a->name == "Player" && b->name == "Enemy")
                            if (isCollide(a, b))
                            {
                                b->life = false;

                                Entity* e = new Entity();
                                e->settings(sExplosion_fish, a->x, a->y);
                                e->name = "boom";
                                entities.push_back(e);

                                P->settings(sPlayer, W / 2, H / 2, 0, 20);
                                P->dx = 0; P->dy = 0;
                            }

                        if (a->name == "Player" && a->x > W - 150)
                        {

                            P->dx -= 0.1;
                        }

                        if (a->name == "Player" && a->x < 0)
                        {
                            Entity* e = new Entity();
                            e->settings(sExplosion_fish, a->x, a->y);
                            e->name = "boom";
                            entities.push_back(e);
                            P->settings(sPlayer, W / 2, H / 2, 0, 20);
                            P->dx = 0; P->dy = 0;
                        }


                        if (a->name == "Player" && a->y > H) a->y = 0;
                        if (a->name == "Player" && a->y < 0) a->y = H;
                    }


                if (P->flow)  P->anim = sPlayer_go;
                else   P->anim = sPlayer;


                for (auto e : entities)
                    if (e->name == "boom")
                        if (e->anim.isEnd()) e->life = 0;

                if (rand() % 300 == 0)
                {
                    Enemy* A = new Enemy();
                    A->settings(sAngry1, 0, rand() % H, 0, 25);
                    entities.push_back(A);
                }

                if (rand() % 300 == 0)
                {
                    Enemy* A = new Enemy();
                    A->settings(sAngry2, 0, rand() % H, 0, 25);
                    entities.push_back(A);
                }

                if (rand() % 300 == 0)
                {
                    Enemy* A = new Enemy();
                    A->settings(sAngry3, 0, rand() % H, 0, 25);
                    entities.push_back(A);
                }

                for (auto i = entities.begin(); i != entities.end();)
                {
                    Entity* e = *i;

                    e->update();
                    e->anim.update();

                    if (e->life == false) { i = entities.erase(i); delete e; }
                    else i++;
                }
                app.clear();

                app.draw(background);
                for (auto i : entities) i->draw(app);
                ostringstream Score;
                Score << schet;
                score.setString("Score:" + Score.str());
                app.draw(score);
                app.display();

            }

           
        }
        else
        {
            menu.interact(app);
            Event event;
            while (app.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    app.close();
            }

        }
    }
        
        
    
	return 0;
}