#include "GameOverScene.h"

void GameOverScene::Initialize()
{
	// --- SCENE & RESOURCE --- //

	scene = new Scene{ };
	resources = new Resources{ scene };


	// --- GAMEOBJECTS --- //

	GameObject* background = scene->createGameObject();
	background->addComponent<PositionComponent>(0, 0);
	background->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\background.bmp", 480, 512);
	background->addComponent<NameComponent>("Background");

	// Title
	GameObject* title = scene->createGameObject();
	title->addComponent<NameComponent>("Title");
	if (information->getVictory() == "X")
	{
		title->addComponent<PositionComponent>(64, 96);
		title->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\victory_x.bmp", 352, 50);
	}
	
	else if (information->getVictory() == "O")
	{
		title->addComponent<PositionComponent>(64, 96);
		title->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\victory_o.bmp", 352, 51);
	}
	
	else if (information->getVictory() == "DRAW")
	{
		title->addComponent<PositionComponent>(64, 96);
		title->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\draw.bmp", 352, 74);
	}

	
	// Restart Button
	GameObject* restart = scene->createGameObject();
	restart->addComponent<NameComponent>("Restart");
	restart->addComponent<PositionComponent>(16, 240);
	restart->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\restart_button\\restart_normal.bmp", 196, 196);
	restart->addComponent<ButtonComponent>(
		"C:\\Users\\lborgesf\\Desktop\\img\\restart_button\\restart_normal.bmp",
		"C:\\Users\\lborgesf\\Desktop\\img\\restart_button\\restart_hover.bmp",
		"C:\\Users\\lborgesf\\Desktop\\img\\restart_button\\restart_hover.bmp",
		128,
		126
	);

	// Home Button
	GameObject* home = scene->createGameObject();
	home->addComponent<NameComponent>("Home");
	home->addComponent<PositionComponent>(268, 240);
	home->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\home_button\\home_normal.bmp", 196, 196);
	home->addComponent<ButtonComponent>(
		"C:\\Users\\lborgesf\\Desktop\\img\\home_button\\home_normal.bmp",
		"C:\\Users\\lborgesf\\Desktop\\img\\home_button\\home_hover.bmp",
		"C:\\Users\\lborgesf\\Desktop\\img\\home_button\\home_hover.bmp",
		128,
		128
	);


	// Controller
	GameObject* menuController = scene->createGameObject();
	menuController->addComponent<NameComponent>("GameOverController");
	menuController->addComponent<PositionComponent>(0, 0);


	// --- SYSTEMS --- //

	resources->add<SpriteSystem>();
	resources->add<ButtonSystem>();

	resources->add<GameOverSystem>();

	resources->configure();
}

void GameOverScene::Start()
{
	resources->init<SpriteSystem>();
	resources->init<ButtonSystem>();

	resources->init<GameOverSystem>();
}

void GameOverScene::Input()
{
	resources->update<ButtonSystem>();
}

void GameOverScene::Update()
{
	resources->update<SpriteSystem>();
	resources->update<GameOverSystem>();
}

void GameOverScene::Free()
{
	resources->free<SpriteSystem>();
	resources->free<ButtonSystem>();

	// To delete Objects is need to delete resouces and scene to after create it again on Initialize() 
	delete resources;
	delete scene;
}