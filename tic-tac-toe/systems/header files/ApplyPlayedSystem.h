#ifndef APPLYPLAYEDSYSTEM_H
#define APPLYPLAYEDSYSTEM_H

// Systems
#include "Requeriment.h"

// Events
#include "PlayedEvent.h"
#include "AppliedPlayedEvent.h"

// Components
#include "PositionComponent.h"
#include "SpawnComponent.h"
#include "BoardComponent.h"

#include "SpriteComponent.h"
#include "NameComponent.h"
#include "TagComponent.h"

#include <map>

class ApplyPlayedSystem : public Requeriment<SpawnComponent, PositionComponent, BoardComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject* obj) override;

		void onPlayed(PlayedEvent* played);

	private:
		void clonePiece(GameObject* oldObj, GameObject* newObj);
		void initializeBoard(int board_x, int board_y, int board_w, int board_h, int sprite_w, int sprite_h);

		bool play;
		std::string turn;
		int x, y;
		
		std::map <std::string, std::pair<std::pair<int, int>, bool>> positions;
		std::string currentPosition;
};

#endif


