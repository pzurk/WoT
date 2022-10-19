#pragma once
#include <SFML/Graphics.hpp>
#include "TankComp.h"
using namespace sf;
using namespace std;

class GTank : public sf::Drawable
{
public:
	GTank(TankComp* ttankc);
	GTank() = delete;
	~GTank() = default;
	TankComp* tankc;
	void draw(RenderTarget & target, RenderStates state) const override;
};

