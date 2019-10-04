#include "GameSystem.h"

void GameSystem::init(GameObject* obj) 
{
	currentTurn = obj->getComponent<TurnComponent>()->currentTurn;
	nextTurn = obj->getComponent<TurnComponent>()->nextTurn;

	eventChannel->subscribe(this, &GameSystem::onAppliedPlayed);
	eventChannel->publish(new TurnEvent(currentTurn));

	initializeBoard();
}


void GameSystem::update(GameObject* obj) { }
void GameSystem::free(GameObject* obj) 
{
	board.clear();
}


void GameSystem::onAppliedPlayed(AppliedPlayedEvent* played)
{
	board.find(played->position)->second = played->turn;

	if (victory(played->turn))
	{
		eventChannel->publish(new VictoryEvent(played->turn));
	}
	
	else if (draw())
	{
		eventChannel->publish(new VictoryEvent("DRAW"));
	}

	else
	{
		std::swap(currentTurn, nextTurn);
		
		eventChannel->publish(new TurnEvent(currentTurn));
	}
}

bool GameSystem::victory(std::string turn)
{
	/*		HORIZONTAL		*/

	if (board.find("Top-Left")->second == turn && board.find("Top-Center")->second == turn && board.find("Top-Right")->second == turn)
	{
		return true;
	}
	
	else if (board.find("Center-Left")->second == turn && board.find("Center-Center")->second == turn && board.find("Center-Right")->second == turn)
	{
		return true;
	}

	if (board.find("Bottom-Left")->second == turn && board.find("Bottom-Center")->second == turn && board.find("Bottom-Right")->second == turn)
	{
		return true;
	}


	/*		VERTICAL	*/	

	else if (board.find("Top-Left")->second == turn && board.find("Center-Left")->second == turn && board.find("Bottom-Left")->second == turn)
	{
		return true;
	}

	else if (board.find("Top-Center")->second == turn && board.find("Center-Center")->second == turn && board.find("Bottom-Center")->second == turn)
	{
		return true;
	}

	if (board.find("Top-Right")->second == turn && board.find("Center-Right")->second == turn && board.find("Bottom-Right")->second == turn)
	{
		return true;
	}


	/*		DIAGONAL	*/

	else if (board.find("Top-Left")->second == turn && board.find("Center-Center")->second == turn && board.find("Bottom-Right")->second == turn)
	{
		return true;
	}

	else if (board.find("Top-Right")->second == turn && board.find("Center-Center")->second == turn && board.find("Bottom-Left")->second == turn)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool GameSystem::draw()
{
	for (auto &piece : board)
	{
		if (piece.second == "")
		{
			return false;
		}
	}
	return true;	
}

void GameSystem::initializeBoard()
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