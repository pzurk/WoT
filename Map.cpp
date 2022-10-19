#include "..\..\..\Users\piotr\source\repos\Game\Game\Map.h"
#include "..\..\..\Users\piotr\source\repos\Game\Game\Map.h"
#include "Map.h"

Map::Map(int win_width, int win_height)
{
	this.win_width = win_width;
	this.win_width = win_width;

}

Map::Map()
{

}
void Map::create_map()
{
}
void Map::createmap(int x, list<Obstacle>& obstacles )
{
	if (x == 1)
	{
		Obstacle obstacle(200,100,30,60);
		obstacles.push_front(obstacle);
		Obstacle obstacle1(200, 300, 30, 60);
		obstacles.push_front(obstacle1);
		Obstacle obstacle2(200, 500, 30, 60);
		obstacles.push_front(obstacle2);
		Obstacle obstacle3(600, 100, 30, 60);
		obstacles.push_front(obstacle3);
		Obstacle obstacle4(600, 300, 30, 60);
		obstacles.push_front(obstacle4);
		Obstacle obstacle5(600, 500, 30, 60);
		obstacles.push_front(obstacle5);
	}
}