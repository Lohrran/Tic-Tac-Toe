#include "MenuScene.h"

void MenuScene::Initialize()
{
	// --- SCENE & RESOURCE --- //

	scene = new Scene{ };
	resources = new Resources{ scene };


	// --- GAMEOBJECTS --- //

	GameObject* background = scene->createGameObject();
	background->addComponent<PositionComponent>(0, 0);
	background->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\background.bmp", 480, 512);
	background->addComponent<NameComponent>("Background");

	GameObject* title = scene->createGameObject();
	title->addComponent<PositionComponent>(48, 64);
	title->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\menu_title.bmp", 384, 128);
	title->addComponent<NameComponent>("Title");

	GameObject* playerVsPlayer = scene->createGameObject();
	playerVsPlayer->addComponent<NameComponent>("Player Vs Player");
	playerVsPlayer->addComponent<PositionComponent>(48, 240);
	playerVsPlayer->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\player_vs_player_button\\player_vs_player_normal.bmp", 384, 87);
	playerVsPlayer->addComponent<ButtonComponent>(
		"C:\\Users\\lborgesf\\Desktop\\img\\player_vs_player_button\\player_vs_player_normal.bmp",
		"C:\\Users\\lborgesf\\Desktop\\img\\player_vs_player_button\\player_vs_player_hover.bmp",
		"C:\\Users\\lborgesf\\Desktop\\img\\player_vs_player_button\\player_vs_player_clicked.bmp",
		384,
		87
	);

	GameObject* playerVsComp = scene->createGameObject();
	playerVsComp->addComponent<NameComponent>("Player Vs Computer");
	playerVsComp->addComponent<PositionComponent>(48, 340);
	playerVsComp->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\player_vs_comp_button\\player_vs_comp_normal.bmp", 384, 87);
	playerVsComp->addComponent<ButtonComponent>(
		"C:\\Users\\lborgesf\\Desktop\\img\\player_vs_comp_button\\player_vs_comp_normal.bmp",
		"C:\\Users\\lborgesf\\Desktop\\img\\player_vs_comp_button\\player_vs_comp_hover.bmp",
		"C:\\Users\\lborgesf\\Desktop\\img\\player_vs_comp_button\\player_vs_comp_clicked.bmp",
		384,
		87
	);

	GameObject* menuController = scene->createGameObject();
	menuController->addComponent<NameComponent>("MenuController");
	menuController->addComponent<PositionComponent>(0, 0);
	

	// --- SYSTEMS --- //

	resources->add<SpriteSystem>();
	resources->add<ButtonSystem>();

	resources->add<MenuSystem>();
	
	resources->configure();
}

void MenuScene::Start()
{
	resources->init<SpriteSystem>();
	resources->init<ButtonSystem>();
	
	resources->init<MenuSystem>();
}

void MenuScene::Input()
{
	resources->update<ButtonSystem>();
}

void MenuScene::Update()
{
	resources->update<SpriteSystem>();
}

void MenuScene::Free()
{
	resources->free<SpriteSystem>();
	resources->free<ButtonSystem>();

	// To delete Objects is need to delete resouces and scene to after create it again on Initialize() 
	delete resources;
	delete scene;
}