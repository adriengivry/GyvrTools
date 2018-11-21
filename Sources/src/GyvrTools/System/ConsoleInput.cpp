#include "GyvrTools/System/ConsoleInput.h"

#include <iostream>

bool GyvrTools::System::ConsoleInput::AskYesOrNoToTheUser(const std::string& p_message)
{
	std::string answer;
	bool answerIsValid = false;
	bool booleanAnswer = false;

	while (!answerIsValid)
	{
		std::cout << p_message << " [Y/n] ";

		std::cin >> answer;

		if (answer == "Y" || answer == "y")
		{
			booleanAnswer = true;
			answerIsValid = true;
		}
		else if (answer == "N" || answer == "n")
		{
			booleanAnswer = false;
			answerIsValid = true;
		}
		else
		{
			std::cout << "Invalid input. Type [Y] or [N] to answer" << std::endl;
		}
	}

	return booleanAnswer;
}

std::string GyvrTools::System::ConsoleInput::AskForString(const std::string & p_message)
{
	std::cout << p_message << " ";
	std::string answer;
	std::cin >> answer;
	return answer;
}

int GyvrTools::System::ConsoleInput::AskForInt(const std::string & p_message)
{
	std::cout << p_message << " ";
	std::string answer;
	std::cin >> answer;
	return std::atoi(answer.c_str());
}

float GyvrTools::System::ConsoleInput::AskForFloat(const std::string & p_message)
{
	std::cout << p_message << " ";
	std::string answer;
	std::cin >> answer;
	return static_cast<float>(std::atof(answer.c_str()));
}
