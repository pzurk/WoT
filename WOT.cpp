#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Tank.h"
#include "Bullet.h"
#include <list>
#include "TankComputer.h"
#include "TankMe.h"
#include "TankComp.h"
#include "Obstacle.h"
#include "Map.h"
#include "GBullet.h"
#include "GTank.h"

using namespace std;
using namespace sf;

int main()
{
	
	list<Obstacle> obstacles = {};

	TankMe tank(400,300,5,1);
	
	int m=5;
	RenderWindow windowm(VideoMode{ tank.winwidth, tank.winheight }, "Menu");
	windowm.setFramerateLimit(60);
	Event eventm;
	while (true)
	{
		windowm.clear(Color::Black);
		windowm.pollEvent(eventm);
		
		if (eventm.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			windowm.close();
			break;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Num1))
		{
			m = 1;
			windowm.close();
			break;
		}
		
		windowm.display();
		
	}
	if (m == 5)
	{
		return 0;
	}

	Map map;

	map.createmap(m, obstacles);


	
	
	RenderWindow window(VideoMode{ tank.winwidth, tank.winheight }, "WoT");
	window.setFramerateLimit(100);
	Event event;
	int x = 0;

	
	list<Bullet> bullets = {};
	list<GBullet> gbullets = {};
	
	list<GTank> gtanks = {};
	list<TankComp> tanks = {};
	

	TankComp* tankc = new TankComp(500, 300, 5, 1);
	GTank gtank(tankc);
	tankc->isenemy = false;
	tankc->shape.setFillColor(Color::Green);
	tanks.push_front(*tankc);
	gtanks.push_front(gtank);


	/*Bullet* bullet = tankc.shoot();
					GBullet gbullet(bullet);
					bullets.push_front(*bullet);
					gbullets.push_front(gbullet);*/

	/*TankComp tankc1(200, 300, 5, 1);
	tankc1.isenemy = true;
	tanks.push_front(tankc1);*/
	
	TankComp* tankc1 = new TankComp(200, 300, 5, 1);
	GTank gtank1(tankc1);
	tankc1->isenemy = true;
	tankc1->shape.setFillColor(Color::Green);
	tanks.push_front(*tankc1);
	gtanks.push_front(gtank1);

	
	//Bullet bullet(-100,-100,1,0);
	int i = 0;
	//int q = 0;
	while (true)
	{
		i++;
		if (i % 1000 == 0)
		{
			int xp = rand() % 300 + 100;
			int yp = rand() % 400 + 100;
			TankComp* tankc = new TankComp(xp, yp, 5, 1);
			GTank gtank(tankc);
			tankc->isenemy = true;
			tanks.push_front(*tankc);
			gtanks.push_front(gtank);
		}
		window.clear(Color::Black);
		window.pollEvent(event);
		if (event.type == Event::Closed|| Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			window.close();
			break;
		}

		//tworzenie pocisków gracza
		
		//tworzenie pocisków komputera
		for (GTank& gtank : gtanks)
		{
			if (gtank.tankc->isenemy)
			{
				if (i % 100 == 0 && !gtank.tankc->isdestroyed)
				{
					/*Bullet* bullet = tankc.shoot();
					GBullet gbullet(bullet);
					bullets.push_front(*bullet);
					gbullets.push_front(gbullet);*/

				}
			}
			else
			{
				if (Keyboard::isKeyPressed(Keyboard::Key::Space))
				{
					x = 0;
				}

				if (event.type == Event::KeyReleased && x == 0)
				{
					if (event.key.code == sf::Keyboard::Space &&
						!Keyboard::isKeyPressed(Keyboard::Key::Left) &&
						!Keyboard::isKeyPressed(Keyboard::Key::Right) &&
						!Keyboard::isKeyPressed(Keyboard::Key::Up) &&
						!Keyboard::isKeyPressed(Keyboard::Key::Down))
					{
						Bullet* bullet = gtank.tankc->shoot();
						bullet->isenemy = false;
						GBullet gbullet(bullet);
						bullets.push_front(*bullet);
						gbullets.push_front(gbullet);
						x = 1;

					}
				}
			}
		}


		/*Bullet* bulletc = tankc.shoot();

		GBullet gbulletc(bulletc);
		bulletsc.push_front(*bulletc);
		gbulletsc.push_front(gbulletc);*/
		
		//rysowanie pocisków 
		for (GBullet& gbullet : gbullets)
		{
			if (!gbullet.bullet->isdestroyed)
			{
				
				window.draw(gbullet);
				gbullet.bullet->update();
				
			}
		}

		//pociski komputera
		
		for (GTank& gtank : gtanks)
		{
			for (GBullet& gbullet : gbullets)
			{
				if (!gtank.tankc->isdestroyed)
				{
					gtank.tankc->ishit(gbullet.bullet);
					
				}
			}
		}
		for (Obstacle& ob : obstacles)
		{
			for (GBullet& gbullet : gbullets)
			{
				ob.ishit(gbullet.bullet);
			}
		}
		for (GBullet& gbullet : gbullets)
		{
			tank.ishit(gbullet.bullet);
		}
		
		
		for (GTank& gtank : gtanks)
		{	
			if (!gtank.tankc->isdestroyed)
			{

				gtank.tankc->update(i, tanks, obstacles);
				window.draw(gtank);
			}
		}
		
		for (Obstacle& ob : obstacles)
		{
			window.draw(ob);
		}
			
		
		window.display();
		
	}
	return 0;
}