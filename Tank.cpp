#include "Tank.h"


using namespace std;

float Tank::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;

}
float Tank::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;

}
float Tank::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float Tank::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Bullet* Tank::shoot()
{
	return new Bullet(this->shape.getPosition().x, this->shape.getPosition().y, this->r, this->bulletvelocity,this->d);
}


void Tank::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
	target.draw(this->shape2, state);
}

bool Tank::collisionhr(Tank tank)
{
	
	if (this->shape.getPosition().x <= tank.shape.getPosition().x && !tank.isdestroyed)
	{
		
		if (this->right() >= tank.left() )
		{
			
			if (this->bottom() >= tank.top() && this->top() <= tank.bottom())
			{
				
				return true;
				
			}
			else
				return false;
			
		}
		
		else 
			return false;
	}
	return false;
	
	
	
}
bool Tank::collisionhl(Tank tank)
{
	if ((this->shape.getPosition().x >= tank.shape.getPosition().x) && !tank.isdestroyed)
	{

	if (this->left() <= tank.right())
	{

		if (this->bottom() >= tank.top() && this->top() <= tank.bottom())
		{

			return true;
		}
		else
			return false;
	}
	else
		return false;
	}
	return false;
}

bool Tank::collisionvt(Tank tank)
{
	
	if (this->shape.getPosition().y >=tank.shape.getPosition().y && !tank.isdestroyed)
	{
		
		if (this->top() <= tank.bottom())
		{
			
			if (this->right() >= tank.left() && this->left() <= tank.right())
			{
				
				return true;
				
				
			}
			else
				return false;

		}

		else
			return false;
	}
	return false;
}
bool Tank::collisionvb(Tank tank)
{
	{
		if (this->shape.getPosition().y <= tank.shape.getPosition().y && !tank.isdestroyed)
		{
			
			if (this->bottom() >= tank.top())
			{
				
				if (this->right() >= tank.left() && this->left() <= tank.right())
				{

					return true;

				}
				else
					return false;

			}

			else
				return false;
		}
		return false;
	}
}

void Tank::ishit(Bullet *bullet)
{
	
	if (bullet->shape.getPosition().x <= this->right()&&
		bullet->shape.getPosition().x >= this->left()&&
		bullet->shape.getPosition().y >= this->top()&&
		bullet->shape.getPosition().y <= this->bottom()&&
		!bullet->isdestroyed&&(bullet->isenemy!=this->isenemy))
	{
		this->isdestroyed = true;
		bullet->destroy();
	}
}





