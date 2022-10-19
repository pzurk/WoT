#pragma once
#include "Tank.h"
class Obstacle : public Tank
{
public:
	Obstacle(float t_x, float t_y, float t_w, float t_h);
	
	Obstacle() = delete;
	~Obstacle() = default;
	void ishit(Bullet* bullet);
	

	

};

