#include "Bullet.h"
#include "Tank.h"
Bullet::Bullet(float t_x, float t_y, float t_r, float t_v,char d)
{
	shape.setPosition(t_x, t_y);
	shape.setRadius(t_r);
	shape.setFillColor(Color::Red);
	shape.setOrigin(t_r, t_r);
	r = t_r;
	v = t_v;
	if (d == 'u')
	{
		velocity.y = -this->v;
		velocity.x = 0;
	}
	else if (d == 'd')
	{
		velocity.y = this->v;
		velocity.x = 0;
	}
	else if (d == 'l')
	{
		velocity.y = 0;
		velocity.x = -this->v;
	}
	else if (d == 'r')
	{
		velocity.y = 0;
		velocity.x = this->v;
	}


	
}
void Bullet::update()
{
	
	shape.move(this->velocity);

}

void Bullet::destroy()
{
	this->isdestroyed = true;
}
