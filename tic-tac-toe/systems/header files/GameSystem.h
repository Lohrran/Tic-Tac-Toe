#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

// System
#include "Requeriment.h"

// Components
#include "NameComponent.h"
#include "TurnComponent.h"

// Events
#include "AppliedPlayedEvent.h"
#include "TurnEvent.h"
#include "VictoryEvent.h"

#include <map>
#include <iostream>

class GameSystem : public Requeriment<NameComponent, TurnComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject* obj) override;

		void onAppliedPlayed(AppliedPlayedEvent* played);

	private:
		bool victory(std::string turn);
		bool draw();

		void initializeBoard();

	private:
		std::map<std::string, std::string> board;

		std::string currentTurn, nextTurn;

};

#endif