#ifndef PLAYEDMOUSESYSTEM_H
#define PLAYEDMOUSESYSTEM_H

#include <string>

// ECS
#include "Requeriment.h"

// Components
#include "MouseComponent.h"
#include "BoardComponent.h"

// Events
#include "MouseEvent.h"
#include "TurnEvent.h"
#include "PlayedEvent.h"
#include "VictoryEvent.h"

class PlayedMouseSystem : public Requeriment<MouseComponent, BoardComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject*obj) override;

		void onTurn(TurnEvent* turnEvent);
		void onMouseClick(MouseEvent* mouse);
		void onVictory(VictoryEvent* victory);

	private:
		std::string turn;
		bool playing;
		int top, bottom, left, right, board_x, board_y;

		std::string translate(int x, int y);
};

#endif