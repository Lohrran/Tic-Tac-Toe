#include "PlayedMouseSystem.h"

void PlayedMouseSystem::init(GameObject* obj) 
{
	playing = true;

	board_x = obj->getComponent<BoardComponent>()->x;
	board_y = obj->getComponent<BoardComponent>()->y;
	
	top = board_y * 3;
	bottom = obj->getComponent<BoardComponent>()->height - board_y;

	left = board_x * 3;
	right = obj->getComponent<BoardComponent>()->width - board_x;


	eventChannel->subscribe(this, &PlayedMouseSystem::onTurn);
	eventChannel->subscribe(this, &PlayedMouseSystem::onMouseClick);
	eventChannel->subscribe(this, &PlayedMouseSystem::onVictory);
}

void PlayedMouseSystem::update(GameObject* obj) { }

void PlayedMouseSystem::free(GameObject* obj) { }

void PlayedMouseSystem::onTurn(TurnEvent* turnEvent)
{
	turn = turnEvent->turn;
}

void PlayedMouseSystem::onMouseClick(MouseEvent* mouse)
{
	if (playing)
	{
		if (mouse->button == "LEFT")
		{
			std::string translation = translate(mouse->x, mouse->y);
			if (translation != "")
			{
				eventChannel->publish(new PlayedEvent(turn, translation));
			}
		}
	}
}

void PlayedMouseSystem::onVictory(VictoryEvent* victory)
{
	playing = false;
}

std::string PlayedMouseSystem::translate(int x, int y)
{
	if (y >= board_y && y < top && x >= board_x && x < left)
	{
		return "Top-Left";
	}

	else if (y >= board_y && y < top && x > left && x < right)
	{
		return "Top-Center";
	}

	else if (y >= board_y && y < top && x > right)
	{
		return "Top-Right";
	}

	else if (y > top && y < bottom && x < left)
	{
		return "Center-Left";
	}

	else if (y > top && y < bottom && x > left && x < right)
	{
		return "Center-Center";
	}

	else if (y > top && y < bottom && x > right)
	{
		return "Center-Right";
	}

	else if (y > bottom && x < left)
	{
		return "Bottom-Left";
	}

	else if (y > bottom && x > left && x < right)
	{
		return "Bottom-Center";
	}

	else if (y > bottom && x > right)
	{
		return "Bottom-Right";
	}

	return "";
}