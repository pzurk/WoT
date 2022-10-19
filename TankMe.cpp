#include "TankMe.h"
#include <list>
TankMe::TankMe(float t_x, float t_y, float t_r, float t_v)
{
	shape.setPosition(t_x, t_y);
	shape.setSize({ this->tankWidth, this->tankHeight });
	shape.setFillColor(Color::White);
	shape.setOrigin(tankWidth / 2.f, tankHeight / 2.f);
	this->isenemy = false;

	r = t_r;
	tankVelocity = { t_v };
	
}
void TankMe::update(list<TankComp>& tanks, list<Obstacle>& obstacles)
{
	this->shape.move(this->velocity);
	bool stop=false;
	//this->shape2.move(this->velocity);
	for (Obstacle& ob : obstacles)
	{
		
			if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0  && !this->collisionhl(ob))
			{
				shape.setRotation(0);

				velocity.x = -tankVelocity;
				velocity.y = 0;
				//shape.setSize({ this->tankWidth, this->tankHeight });
				this->d = 'l';
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < winwidth  && !this->collisionhr(ob))
			{
				shape.setRotation(180);


				velocity.x = tankVelocity;
				velocity.y = 0;
				//shape.setSize({ this->tankWidth, this->tankHeight });
				this->d = 'r';

			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->top() > 0  && !this->collisionvt(ob))
			{
				shape.setRotation(270);

				velocity.y = -tankVelocity;
				velocity.x = 0;
				//shape.setSize({ this->tankHeight, this->tankWidth });
				this->d = 'u';
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->bottom() < winheight  && !this->collisionvb(ob))
			{

				shape.setRotation(90);

				velocity.y = tankVelocity;
				velocity.x = 0;
				//shape.setSize({ this->tankHeight, this->tankWidth });
				this->d = 'd';
			}

			else
			{
				
				stop = true;
				velocity.x = 0;
				velocity.y = 0;
				break;
			}
	}
	if (!stop)
	{
		for (TankComp& tank : tanks)
		{

			if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0 && !this->collisionhl(tank))
			{
				shape.setRotation(0);

				velocity.x = -tankVelocity;
				velocity.y = 0;
				//shape.setSize({ this->tankWidth, this->tankHeight });
				this->d = 'l';
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < winwidth && !this->collisionhr(tank))
			{
				shape.setRotation(180);


				velocity.x = tankVelocity;
				velocity.y = 0;
				//shape.setSize({ this->tankWidth, this->tankHeight });
				this->d = 'r';

			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->top() > 0 && !this->collisionvt(tank))
			{
				shape.setRotation(270);

				velocity.y = -tankVelocity;
				velocity.x = 0;
				//shape.setSize({ this->tankHeight, this->tankWidth });
				this->d = 'u';
			}
			else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->bottom() < winheight && !this->collisionvb(tank))
			{

				//		shape.setRotation(90);

				velocity.y = tankVelocity;
				velocity.x = 0;
				//shape.setSize({ this->tankHeight, this->tankWidth });
				this->d = 'd';
			}

			else
			{

				velocity.x = 0;
				velocity.y = 0;
				break;
			}
		}
	}

}
//void TankMe::draw(RenderTarget& target, RenderStates state) const
//{
//	target.draw(this->shape, state);
//}
