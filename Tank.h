#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "Bullet.h"
#include <iostream>
#include <list>
//#include <Texture.hpp>

using namespace sf;
using namespace std;

class Tank : public sf::Drawable
{
public:
	/*Tank(float t_x, float t_y, float t_r, float t_v);
	Tank() = delete;
	~Tank() = default;*/
	//void update();

	float left();
	float right();
	float top();
	float bottom();
	float bulletvelocity=5;
	float r = { 3 };
	float v = { 3 };
	char d='r';
	unsigned int winwidth =1070;
	unsigned int winheight = 600;
	bool isdestroyed = false;

	

	//RectangleShape shape;
	
	Bullet* shoot();

	bool isenemy;
	Vector2f getPosition();
//private:
	void draw(RenderTarget& target, RenderStates state) const override;
	
	bool collisionhl(Tank tank);
	bool collisionhr(Tank tank);
	bool collisionvt(Tank tank);
	bool collisionvb(Tank tank);
	void ishit(Bullet *bullet);

	RectangleShape shape;
	RectangleShape shape2;
	float tankWidth{ 30.0f };
	float tankHeight{ 25.0f };
	float tankVelocity{ 6.0f };
	Vector2f velocity{ tankVelocity, tankVelocity};

};

