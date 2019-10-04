#include "PlayerVsPlayerScene.h"

void PlayerVsPlayerScene::Initialize()
{
	// --- SCENE & RESOURCE --- //

	scene = new Scene{ };
	resources = new Resources{ scene };

	// --- GAMEOBJECTS --- //

	GameObject* background = scene->createGameObject();
	background->addComponent<TagComponent>("Background");
	background->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\background.bmp", 1028, 1028);
	background->addComponent<PositionComponent>(0, 0);

	GameObject* board = scene->createGameObject();
	board->addComponent<TagComponent>("Board");
	board->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\board.bmp", 384, 384);
	board->addComponent<PositionComponent>((camera->surface()->w / 2) - (384 / 2), (camera->surface()->h / 2) - (384 / 2)); // Center Board

	GameObject* controller = scene->createGameObject();
	controller->addComponent<MouseComponent>();
	controller->addComponent<BoardComponent>(
		(camera->surface()->w / 2) - (384 / 2),
		(camera->surface()->h / 2) - (384 / 2),
		384,
		384
	);


	GameObject* player_one = scene->createGameObject();
	player_one->addComponent<TagComponent>("Player");
	player_one->addComponent<NameComponent>("X");
	player_one->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\X.bmp", 124, 124);
	player_one->addComponent<PositionComponent>(0, -10000);

	GameObject* player_two = scene->createGameObject();
	player_two->addComponent<TagComponent>("Player");
	player_two->addComponent<NameComponent>("O");
	player_two->addComponent<SpriteComponent>("C:\\Users\\lborgesf\\Desktop\\img\\O.bmp", 124, 124);
	player_two->addComponent<PositionComponent>(0, -10000);


	// Game Rules
	GameObject* game = scene->createGameObject();
	game->addComponent<NameComponent>("Game Rules");
	game->addComponent<TurnComponent>("X", "O");


	// Spawn the piece of the players
	GameObject* spawn = scene->createGameObject();
	spawn->addComponent<PositionComponent>(0, 0);
	spawn->addComponent<SpawnComponent>();

	spawn->getComponent<SpawnComponent>()->add(
		player_one->getComponent<NameComponent>()->name,
		player_one
	);

	spawn->getComponent<SpawnComponent>()->add(
		player_two->getComponent<NameComponent>()->name,
		player_two
	);

	spawn->addComponent<BoardComponent>(
		(camera->surface()->w / 2) - (384 / 2),
		(camera->surface()->h / 2) - (384 / 2),
		384,
		384
	);

	GameObject* victory = scene->createGameObject();
	victory->addComponent<NameComponent>("Victory");
	victory->addComponent<PositionComponent>(0, 0);


	// --- SYSTEMS --- //

	resources->add<SpriteSystem>();
	resources->add<MouseSystem>();

	resources->add<GameSystem>();
	resources->add<PlayedMouseSystem>();
	resources->add<ApplyPlayedSystem>();
	resources->add<VictorySystem>();

	resources->configure();
}

void PlayerVsPlayerScene::Start()
{
	resources->init<SpriteSystem>();
	resources->init<MouseSystem>();

	resources->init<PlayedMouseSystem>();
	resources->init<GameSystem>();
	resources->init<ApplyPlayedSystem>();
	resources->init<VictorySystem>();
}

void PlayerVsPlayerScene::Input()
{
	resources->update<MouseSystem>();
}

void PlayerVsPlayerScene::Update()
{
	resources->update<SpriteSystem>();

	resources->update<VictorySystem>();
	resources->update<GameSystem>();
	resources->update<PlayedMouseSystem>();
	resources->update<ApplyPlayedSystem>();
}

void PlayerVsPlayerScene::Free()
{
	resources->free<SpriteSystem>();
	resources->free<ApplyPlayedSystem>();
	resources->free<GameSystem>();

	// To delete Objects is need to delete resouces and scene to after create it again on Initialize() 
	delete resources;
	delete scene;
}