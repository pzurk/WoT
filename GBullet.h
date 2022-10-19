#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
using namespace sf;
using namespace std;

class GBullet : public sf::Drawable
{
public:
	GBullet(Bullet *tbullet);
	GBullet() = delete;
	~GBullet() = default;
	Bullet* bullet;
	void draw(RenderTarget& target, RenderStates state) const override;
};

