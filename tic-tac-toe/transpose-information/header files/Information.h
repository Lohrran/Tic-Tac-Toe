#ifndef INFORMATION_H
#define INFORMATION_H

#include <string>
#include <memory>

class Information
{
	public:
		Information();

		Information(const Information&) = delete;
		Information& operator = (const Information&) = delete;

		static std::shared_ptr<Information> get();

		static std::string getVictory();
		static void setVictory(std::string state);

		static std::string getPreviousScene();
		static void setScene(std::string scene);

	private:
		static std::shared_ptr<Information> instance;

		static std::string victory;
		static std::string previousScene;
};
#endif