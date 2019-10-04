//Inverse Double NES Resolution
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 512

// ENGINE
#include "TinyEngine2D.h"

// GAME SCENES
#include "MenuScene.h"
#include "PlayerVsPlayerScene.h"
#include "PlayerVsCompScene.h"
#include "GameOverScene.h"

#include <iostream>

int main(int argc, char *argv[])
{
	TinyEngine2D engine{ "Tic-Tac-Toe", SCREEN_WIDTH, SCREEN_HEIGHT };

	engine.addGameScene("Home Menu", new MenuScene{ });
	engine.addGameScene("Player Vs Player", new PlayerVsPlayerScene{ });
	engine.addGameScene("Player Vs Computer", new PlayerVsCompScene{ });
	engine.addGameScene("Game Over Menu", new GameOverScene{ });

	engine.setFirstGameScene("Home Menu");

	engine.play();

	std::cout << "\n\n\n";
	system("pause");
	return 0;
}