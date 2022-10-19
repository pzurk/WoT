#pragma once
#include "Tank.h"
#include "TankComp.h"
#include "Obstacle.h"

using namespace sf;
using namespace std;
class TankMe :  public Tank
{
public:
	TankMe(float t_x, float t_y, float t_r, float t_v);
	
	TankMe() = delete;
	~TankMe() = default;
	void update(list<TankComp>& tanks, list<Obstacle>& obstacles);
	/*RectangleShape shape;
	Vector2f getPosition();
	void draw(RenderTarget& target, RenderStates state) const override;
	Vector2f velocity{ tankVelocity, tankVelocity };*/
};

