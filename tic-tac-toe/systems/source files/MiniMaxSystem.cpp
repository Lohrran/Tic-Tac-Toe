#include "MiniMaxSystem.h"

void MiniMaxSystem::init(GameObject* obj)
{
	play = obj->getComponent<MiniMaxComponent>()->start;

	myDepth = obj->getComponent<MiniMaxComponent>()->depth;
	myself = obj->getComponent<NameComponent>()->name;

	//Find Opponent name
	opponent = myself == "O" ? "X" : "O";

	eventChannel->subscribe(this, &MiniMaxSystem::onAppliedPlayed);
	eventChannel->subscribe(this, &MiniMaxSystem::onTurn);

	initializeBoard();
}

void MiniMaxSystem::update(GameObject* obj)
{
	if (play)
	{
		Move myMove = getBestMove();
		eventChannel->publish(new PlayedEvent(myself, myMove.position));
		
		play = false;
	}
}

void MiniMaxSystem::free(GameObject* obj) { }

void MiniMaxSystem::onAppliedPlayed(AppliedPlayedEvent* played)
{
	board.find(played->position)->second = played->turn;
}

void MiniMaxSystem::onTurn(TurnEvent* turn)
{
	if (turn->turn == myself)
	{
		currentTurn = turn->turn;
		play = true;
	}
}

bool MiniMaxSystem::isFull()
{
	for (auto &child : board)
	{
		if (child.second == "")
		{
			return false;
		}
	}
	return true;
}

int MiniMaxSystem::evaluate(std::string turn)
{
	/*		HORIZONTAL		*/

	if (board.find("Top-Left")->second == turn && board.find("Top-Center")->second == turn && board.find("Top-Right")->second == turn)
	{
		return turn == myself ? +10 : -10;
	}

	else if (board.find("Center-Left")->second == turn && board.find("Center-Center")->second == turn && board.find("Center-Right")->second == turn)
	{
		return turn == myself ? +10 : -10;
	}

	if (board.find("Bottom-Left")->second == turn && board.find("Bottom-Center")->second == turn && board.find("Bottom-Right")->second == turn)
	{
		return turn == myself ? +10 : -10;
	}


	/*		VERTICAL	*/

	else if (board.find("Top-Left")->second == turn && board.find("Center-Left")->second == turn && board.find("Bottom-Left")->second == turn)
	{
		return turn == myself ? +10 : -10;
	}

	else if (board.find("Top-Center")->second == turn && board.find("Center-Center")->second == turn && board.find("Bottom-Center")->second == turn)
	{
		return turn == myself ? +10 : -10;
	}

	if (board.find("Top-Right")->second == turn && board.find("Center-Right")->second == turn && board.find("Bottom-Right")->second == turn)
	{
		return turn == myself ? +10 : -10;
	}


	/*		DIAGONAL	*/

	else if (board.find("Top-Left")->second == turn && board.find("Center-Center")->second == turn && board.find("Bottom-Right")->second == turn)
	{
		return turn == myself ? +10 : -10;
	}

	else if (board.find("Top-Right")->second == turn && board.find("Center-Center")->second == turn && board.find("Bottom-Left")->second == turn)
	{
		return turn == myself ? +10 : -10;
	}

	return 0;
}

int MiniMaxSystem::minimizer(int depth, bool isMax, std::string turn)
{
	int best = 1000;

	for (auto &child : board)
	{
		if (child.second == "")
		{
			child.second = opponent;
			
			best = std::min(best, minimax(depth, isMax, turn));

			child.second = "";
		}
	}
	return best;
}

int MiniMaxSystem::maximazer(int depth, bool isMax, std::string turn)
{
	int best = -1000;

	for (auto &child : board)
	{
		if (child.second == "")
		{
			child.second = myself;
			
			best = std::max(best, minimax(depth, isMax, turn));
			
			child.second = "";
		}
	}
	return best;
}

int MiniMaxSystem::minimax(int depth, bool isMax, std::string turn)
{
	int score = evaluate(turn);

	if (score == 10 || score == -10)
	{
		return score;
	}

	if (isFull())
	{
		return 0;
	}

	if (isMax)
	{
		return maximazer(depth + 1, !isMax, myself);
	}

	else
	{
		return minimizer(depth + 1, !isMax, opponent);
	}
}

Move MiniMaxSystem::getBestMove()
{
	int bestValue = -1000;
	Move bestMove;
	bestMove.position = "";

	for (auto &child : board)
	{
		if (child.second == "")
		{
			child.second = myself;
			
			int move = minimax(myDepth, false, myself);

			child.second = "";
			
			if (move > bestValue)
			{
				bestMove.position = child.first;
				bestValue = move;
			}
		}
	}
	return bestMove;
}

void MiniMaxSystem::initializeBoard()
{
	// Positions
	board.insert({ "Top-Left", "" });
	board.insert({ "Top-Center", "" });
	board.insert({ "Top-Right", "" });
	board.insert({ "Center-Left", "" });
	board.insert({ "Center-Left", "" });
	board.insert({ "Center-Center", "" });
	board.insert({ "Center-Right", "" });
	board.insert({ "Bottom-Left", "" });
	board.insert({ "Bottom-Center", "" });
	board.insert({ "Bottom-Right", "" });
}