#include "Obstacle.h"
Obstacle::Obstacle(float t_x, float t_y, float t_w, float t_h)
{
	shape.setPosition(t_x, t_y);
	shape.setSize({ t_w, t_h });
	shape.setFillColor(Color::Magenta);
	shape.setOrigin(t_w / 2, t_h / 2);
	
}
void Obstacle::ishit(Bullet* bullet)
{
	if (bullet->shape.getPosition().x <= this->right() &&
		bullet->shape.getPosition().x >= this->left() &&
		bullet->shape.getPosition().y >= this->top() &&
		bullet->shape.getPosition().y <= this->bottom() &&
		!bullet->isdestroyed)
	{
		
		bullet->destroy();
	}
}

