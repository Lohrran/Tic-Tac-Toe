#include "Information.h"

std::shared_ptr<Information> Information::instance = nullptr;
std::string Information::victory = "";
std::string Information::previousScene = "";

Information::Information() { }

std::shared_ptr<Information> Information::get()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<Information>();
	}
	return instance;
}

std::string Information::getVictory()
{
	return victory;
}

void Information::setVictory(std::string vic)
{
	victory = vic;
}

std::string Information::getPreviousScene()
{
	return previousScene;
}

void Information::setScene(std::string scene)
{
	previousScene = scene;
}