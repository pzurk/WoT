#include "..\..\..\Users\piotr\source\repos\Game\Game\GTank.h"
#include "GTank.h"

GTank::GTank(TankComp* ttankc)
{
	this->tankc = ttankc;
}


void GTank::draw(RenderTarget& target, RenderStates state)const
{
	target.draw(this->tankc->shape, state);
}
