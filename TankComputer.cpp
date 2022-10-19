#include "TankComputer.h"
TankComputer::TankComputer(float t_x, float t_y, float t_r, float t_v)
{
	shape.setPosition(t_x, t_y);
	shape.setSize({ this->tankWidth, this->tankHeight });
	shape.setFillColor(Color::Green);
	shape.setOrigin(tankWidth / 2.f, tankHeight / 2.f);
	r = t_r;
	v = t_v;
}

