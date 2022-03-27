#include "game.h"
#include "const.h"
#include <iostream>
Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close),
	game_over_screen(IMAGES_FOLDER + GAME_OVER_FILE_NAME, 1.2f, 1.43f),
	prav_screen(IMAGES_FOLDER + GAME_OVER_FILE_NAME, 1.2f, 1.43f),
	score_text( "DS-DIGIB.TTF", 100, 70, 60, sf::Color::White),
	intro_screen(IMAGES_FOLDER + INTRO_FILE_NAME, 1.351f, 2.135f),
	river1(0.f, 0.f),
	river2(0.f, -WINDOW_HEIGHT)
{
	window.setVerticalSyncEnabled(true);
	for (size_t i = 0; i < BARIER_QTY; i++) {
		Barier* barier= new Barier();
		bariers.push_back(barier);
	}
	/*for (size_t i = 0; i < ISLANDS_TYPE_QTY; i++) {
		Islands* islands = new Islands();
		island.push_back(island);
	}*/
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		if (event.type == sf::Event::KeyPressed) {
			if (game_state == INTRO && event.key.code == sf::Keyboard::Space) {
				game_state = PRAV;
				if (game_state == PRAV && event.key.code == sf::Keyboard::Space) {
					game_state = PLAY;
				}
			}
		}
	}
}
void Game::update() {
	switch (game_state) {
	case INTRO:
		break;
	case PRAV:
		break;
	case PLAY:
		river1.update();
		river2.update();
		player.update();
		for (size_t i = 0; i < BARIER_QTY; i++) {
			bariers[i]->update();
		}
		//for (auto iter = explosions.begin(); iter != explosions.end(); iter++) {
		//	(*iter)->update();
		//}
		/*for (size_t i = 0; i < ISLANDS_TYPE_QTY; i++) {
			island[i]->update();
		}*/
		break;
	case GAME_OVER:
		break;
	}
}
	void Game::draw() {
		window.clear(sf::Color::Black);
		switch (game_state) {
		case INTRO:
			window.clear(sf::Color(150, 150, 150));
			window.draw(game_over_screen.getSprite());
			break;
		case PRAV:
			window.clear(sf::Color(150, 150, 150));
			window.draw(intro_screen.getSprite());
			break;
		case PLAY:
			river2.draw(window);
			river1.draw(window);
			player.draw(window);
			for (size_t i = 0; i < BARIER_QTY; i++) {
				bariers[i]->draw(window);
			};
			//for (auto iter = explosions.begin(); iter != explosions.end(); iter++) {
			//	(*iter)->draw(window);
			//}
			/*for (size_t i = 0; i < ISLANDS_TYPE_QTY; i++) {
				island[i]->draw(window);
			}*/
			window.draw(score_text.getText());
			break;
		case GAME_OVER:
		 window.clear(sf::Color(150, 150, 150));
		window.draw(intro_screen.getSprite());
			break;
		}
		window.display();
	}
	void Game::check_collisions() {
		for (auto iter = bariers.begin(); iter != bariers.end(); iter++) {
			if (player.getHitBox().intersects((*iter)->getHitBox())) {
				fg = fg + 1;
				(*iter)->spawn();
				if (fg == 5) {
					
					game_state = GAME_OVER;
				}
			}
		}
		/*for (auto it_l = players.begin(); it_l != players.end(); it_l++) {
			for (auto it_m = bariers.begin(); it_m != bariers.end(); it_m++) {
				if ((*it_l)->getHitBox().intersects((*it_m)->getHitBox())) {
					score += 50 - static_cast<size_t>((*it_m)->getHitBox().width / 3);
					Explosion* new_exp = new Explosion((*it_m)->getPosition());
					explosions.push_back(new_exp);
					(*it_m)->spawn();
					(*it_l)->setDel(true);
				}
			}
		}
		explosions.remove_if([](Explosion* exp) {return exp->getDel(); });*/
	}
	