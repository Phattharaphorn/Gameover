#pragma once
#include <SFML/Graphics.hpp>
#define GAMEOVER_ITEMS 3 //back exit 
class Gameover
{
public:
	Gameover(float width, float height);
	~Gameover();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	
private:
	int selectedItem;
	sf::Vector2f size;
	sf::Vector2f position;
	sf::Font font;
	sf::Text gameover[GAMEOVER_ITEMS]; //back exit 
	sf::Texture gameoverTexture;
	sf::Sprite gameoverSprite;
};

