#pragma once
#include "Tank.h"
using namespace sf;
using namespace std;
class TankComputer : public Tank 
{
public:
	TankComputer(float t_x, float t_y, float t_r, float t_v);
	TankComputer() = delete;
	~TankComputer() = default;
	//void update();
	
};
