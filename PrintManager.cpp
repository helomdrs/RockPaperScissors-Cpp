#include "PrintManager.h"

//Private
void PrintManager::PrintHashLine(const int& charPerLine, std::string& finalString)
{
	for (int i = 1; i < charPerLine; i++)
	{
		finalString.append(availableStrings[0]);
	};

	finalString.append("\n");
}

void PrintManager::PrintBlankLine(const int& charPerLine, std::string& finalString)
{
	for (int i = 1; i < charPerLine; i++)
	{
		if (i <= 2 || i >= 58) {
			finalString.append(availableStrings[0]);
		}
		else {
			finalString.append(" ");
		}
	}

	finalString.append("\n");
}

void PrintManager::PrintTitle(const int& charPerLine, std::string& finalString, int titleLevel)
{
	for (int i = 1; i <= charPerLine; i++)
	{
		if (i <= 2 || i >= 59) {
			finalString.append(availableStrings[0]);
		}
		else if (i == std::round((30 - availableStrings[titleLevel].length() / 2)))
		{
			finalString.append(availableStrings[titleLevel]);
			i += availableStrings[titleLevel].length();
		}
		else {
			finalString.append(" ");
		}
	}

	finalString.append("\n");
}

void PrintManager::SimplePrint(int index, bool endl)
{
	if (endl)
		std::cout << availableStrings[index] << std::endl;
	else
		std::cout << availableStrings[index];
}

//Public
void PrintManager::PrintHeader()
{
	std::string toPrint = "";
	const int charPerLine = 60;

	PrintHashLine(charPerLine, toPrint);
	PrintBlankLine(charPerLine, toPrint);
	PrintTitle(charPerLine, toPrint, 1);
	PrintTitle(charPerLine, toPrint, 2);
	PrintBlankLine(charPerLine, toPrint);
	PrintHashLine(charPerLine, toPrint);

	std::cout << toPrint << std::endl;
}

void PrintManager::PrintScore(int& scorePlayer, int& scoreAI)
{
	std::printf(availableStrings[5].c_str(), scorePlayer, scoreAI);
}

void PrintManager::PrintMainMenu()
{
	SimplePrint(3, false);
}

void PrintManager::PrintMatchOptions()
{
	SimplePrint(4, false);
}

void PrintManager::PrintMatchMoves(std::string playerMove, std::string aiMove)
{
	std::printf(availableStrings[10].c_str(), playerMove.c_str(), aiMove.c_str());
}

void PrintManager::PrintDraw()
{
	SimplePrint(6, true);
}

void PrintManager::PrintPlayerWon()
{
	SimplePrint(7, true);
}

void PrintManager::PrintAIWon()
{
	SimplePrint(8, true);
}

void PrintManager::ClearScreen()
{
	system("cls");
	PrintHeader();
}
