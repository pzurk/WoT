#pragma once
#include "Obstacle.h"
class Map
{
public:
	Map();
	//Map() = delete;
	~Map() = default;
	void createmap(int x, list<Obstacle>& obstacles);
};

