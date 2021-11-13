#include "Gameover.h"

Gameover::Gameover(float width, float height)
{
	this->size = sf::Vector2f(800.0f, 600.0f);
	selectedItem = 0;

	gameoverTexture.loadFromFile("backgroundover1.jpg");
	gameoverSprite.setTexture(gameoverTexture);

	if(!font.loadFromFile("SDfont.ttf"))
	{
		//handle error
	}
	gameover[0].setFont(font);
	gameover[0].setCharacterSize(60);
	gameover[0].setFillColor(sf::Color::Yellow);
	gameover[0].setString("Back");
	gameover[0].setOrigin(gameover[0].getGlobalBounds().width / 2, gameover[0].getGlobalBounds().height / 1);
	gameover[0].setPosition(sf::Vector2f(width / 1.95, height / (GAMEOVER_ITEMS + 1) * 2));

	gameover[1].setFont(font);
	gameover[1].setCharacterSize(60);
	gameover[1].setFillColor(sf::Color::Color(224, 250, 132));
	gameover[1].setString("Exit");
	gameover[1].setOrigin(gameover[1].getGlobalBounds().width / 2, gameover[1].getGlobalBounds().height / 2);
	gameover[1].setPosition(sf::Vector2f(width / 1.95, height / (GAMEOVER_ITEMS + 1) * 2.3));

	gameover[2].setFont(font);
	gameover[2].setCharacterSize(60);
	gameover[2].setFillColor(sf::Color::Color(224, 250, 132));
	gameover[2].setString("Score");
	gameover[2].setOrigin(gameover[1].getGlobalBounds().width / 2, gameover[2].getGlobalBounds().height / 3);
	gameover[2].setPosition(sf::Vector2f(width / 2.05, height / (GAMEOVER_ITEMS + 1) * 2.65));

}

Gameover::~Gameover()
{

}

void Gameover::draw(sf::RenderWindow& window)
{
	window.draw(gameoverSprite);
	for (int i = 0; i < GAMEOVER_ITEMS; i++)
	{
		window.draw(gameover[i]);
	}
}

void Gameover::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		gameover[selectedItem].setFillColor(sf::Color::Color(224, 250, 132));
		selectedItem--;
		gameover[selectedItem].setFillColor(sf::Color::Yellow);

	}
}

void Gameover::MoveDown()
{
	if (selectedItem + 1 < GAMEOVER_ITEMS)
	{

		gameover[selectedItem].setFillColor(sf::Color::Color(224, 250, 132));
		selectedItem++;
		gameover[selectedItem].setFillColor(sf::Color::Yellow);

	}
}
