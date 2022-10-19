#pragma once
#include <SFML/Graphics.hpp>
//#include "GBullet.h"


using namespace sf;
using namespace std;
class Bullet
{
public:
	Bullet(float t_x, float t_y, float t_r, float t_v,char d);
	Bullet() = delete;
	~Bullet() = default;

	bool isenemy = true;

	Vector2f getPosition();
	void destroy();
	void update();
	float v;
	bool isdestroyed = false;
	float r;
	CircleShape shape;
	
	float bulletvelocity {6};
	Vector2f velocity{ bulletvelocity,bulletvelocity};
	
};

