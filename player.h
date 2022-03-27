#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"
class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	bool del = false;
public:
	Player();
	void update();
	void draw(sf::RenderWindow& window);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	void setDel(bool);
	bool getDel();
};