#pragma once
#include "SFML/Graphics.hpp"
#include "player.h"
#include"const.h"
#include"river.h"
#include"barier.h"
#include"splash.h"
#include"text.h"
#include"islands.h"
#include"bang.h"
#include<list>
#include <vector>
class Game {
public:
	enum GameState { INTRO,PRAV, PLAY, GAME_OVER };
	Game();
	void play();
	void check_events();
	void update();
	void draw();
	void check_collisions();
	int fg = 0;
	
private:
	sf::RenderWindow window;
	GameState game_state = INTRO;
	Player player;
	std::vector<Barier*> bariers;
	//std::vector<Islands*> island;
	River river1, river2;
	SplashScreen  intro_screen, game_over_screen,prav_screen;
	TextObject score_text;
	//std::list<Explosion*> explosions;
	//std::list<Player*> players;
	//size_t score = 0;
};