#ifndef MINIMAXSYSTEM_H
#define MINIMAXSYSTEM_H

#include <map>
#include <string>

// ECS
#include "Requeriment.h"

// Components
#include "MiniMaxComponent.h"
#include "NameComponent.h"

// Events
#include "AppliedPlayedEvent.h"
#include "TurnEvent.h"
#include "PlayedEvent.h"

struct Move
{
	std::string position;
};

class MiniMaxSystem : public Requeriment<MiniMaxComponent, NameComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject* obj) override;

		// Events
		void onAppliedPlayed(AppliedPlayedEvent* played);
		void onTurn(TurnEvent* turn);

	private:
		// Minimax
		bool isFull();
		int evaluate(std::string turn);

		int minimizer(int depth, bool isMax, std::string turn);
		int maximazer(int depth, bool isMax, std::string turn);

		int minimax(int depth, bool isMax, std::string turn);
		Move getBestMove();
		
		void initializeBoard();

		int myDepth;
		bool play;
		std::map<std::string, std::string> board;
		std::string currentTurn, myself, opponent;
};
#endif