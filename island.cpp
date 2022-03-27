/*#include"islands.h"
#include"const.h"
std::string Islands::islands_file_names[] = {
	"tile_01.png"
	"tile_02.png"
	"tile_04.png"
	"tile_03.png"
};
Islands::Islands() {
	size_t num = rand() % ISLANDS_TYPE_QTY;
	texture.loadFromFile(IMAGES_FOLDER + islands_file_names[num]);
	sprite.setTexture(texture);
	spawn();
}
void Islands::update() {
	sprite.move(speedx, speedy);
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	if (sprite.getPosition().x < 0 - g_bound.width ||
		sprite.getPosition().x > WINDOW_WIDTH ||
		sprite.getPosition().y > WINDOW_HEIGHT)
	{
		spawn();
	}
}
void Islands::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Islands::spawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = rand() % (static_cast<size_t>(WINDOW_WIDTH) -
		static_cast<size_t>(g_bound.width));
	float y = rand() % (static_cast<size_t>(WINDOW_HEIGHT)) - WINDOW_HEIGHT;
	sprite.setPosition(x, y);
	speedx = rand() % 5 - 2;
	speedy = rand() % 8 + 2;
}
sf::FloatRect Islands::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Islands::getPosition() { return sprite.getPosition(); }*/