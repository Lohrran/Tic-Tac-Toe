#include "ApplyPlayedSystem.h"

void ApplyPlayedSystem::init(GameObject* obj)
{
	play = false;

	eventChannel->subscribe(this, &ApplyPlayedSystem::onPlayed);

	initializeBoard
	(
		obj->getComponent<BoardComponent>()->x,
		obj->getComponent<BoardComponent>()->y,
		obj->getComponent<BoardComponent>()->width,
		obj->getComponent<BoardComponent>()->height,
		obj->getComponent<SpawnComponent>()->spawnableds.find("X")->second->getComponent<SpriteComponent>()->width,
		obj->getComponent<SpawnComponent>()->spawnableds.find("X")->second->getComponent<SpriteComponent>()->height
	);
}

void ApplyPlayedSystem::update(GameObject* obj)
{
	if (play)
	{
		// Get List of Spawnables Objects
		std::map <std::string, GameObject*> spawnableds = obj->getComponent<SpawnComponent>()->spawnableds;

		// Get Correct Reference of Spawnable
		GameObject* spawnabled = spawnableds.find(turn)->second;
		spawnabled->getComponent<SpriteComponent>()->enabled = false;

		// Clone Spawnable and Place in correct position
		GameObject* newObj = scene->createGameObject();
		clonePiece(spawnabled, newObj);

		eventChannel->publish(new AppliedPlayedEvent(turn, currentPosition));

		play = false;
	}
}

void ApplyPlayedSystem::free(GameObject* obj) 
{
	positions.clear();
}

void ApplyPlayedSystem::onPlayed(PlayedEvent* played)
{
	turn = played->turn;
	if (!positions.find(played->position)->second.second) // Validate if this position was not used
	{
		// Get exact position to create piece;
		x = positions.find(played->position)->second.first.first;
		y = positions.find(played->position)->second.first.second;

		positions.find(played->position)->second.second = true; // Set as used

		currentPosition = played->position;
		play = true;// Apply move
	}
}

void ApplyPlayedSystem::clonePiece(GameObject* oldObj, GameObject* newObj)
{
	newObj->addComponent<TagComponent>("Piece");

	newObj->addComponent<NameComponent>
	(
		oldObj->getComponent<NameComponent>()->name
	);

	newObj->addComponent<SpriteComponent>
	(
		oldObj->getComponent<SpriteComponent>()->path,
		oldObj->getComponent<SpriteComponent>()->width,
		oldObj->getComponent<SpriteComponent>()->height
	);

	SDL_Surface* oldSurface = oldObj->getComponent<SpriteComponent>()->sprite;
	SDL_Surface* newSurface = new SDL_Surface{ *oldSurface };

	newObj->getComponent<SpriteComponent>()->sprite = newSurface;

	newObj->addComponent<PositionComponent>(x, y);
}

void ApplyPlayedSystem::initializeBoard(int board_x, int board_y, int board_w, int board_h, int sprite_w, int sprite_h)
{
	int top, bottom, left, right, center_c, center_r;

	top = board_y;
	left = board_x;
	center_c = (board_w / 2) + board_x - (sprite_w / 2);
	center_r = (board_w / 2) + board_y - (sprite_w / 2);
	bottom = board_h - (sprite_h / 2);
	right = (board_w + board_x) - sprite_w;

	positions.insert(std::make_pair("Top-Left", std::make_pair(std::make_pair(left, top), false)));
	positions.insert(std::make_pair("Top-Center", std::make_pair(std::make_pair(center_c, top), false)));
	positions.insert(std::make_pair("Top-Right", std::make_pair(std::make_pair(right, top), false)));
	positions.insert(std::make_pair("Center-Left", std::make_pair(std::make_pair(left, center_r), false)));
	positions.insert(std::make_pair("Center-Center", std::make_pair(std::make_pair(center_c, center_r), false)));
	positions.insert(std::make_pair("Center-Right", std::make_pair(std::make_pair(right, center_r), false)));
	positions.insert(std::make_pair("Bottom-Left", std::make_pair(std::make_pair(left, bottom), false)));
	positions.insert(std::make_pair("Bottom-Center", std::make_pair(std::make_pair(center_c, bottom), false)));
	positions.insert(std::make_pair("Bottom-Right", std::make_pair(std::make_pair(right, bottom), false)));
} 