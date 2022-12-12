#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

enum result {
	Rock,
	Paper,
	Scissors
};

enum roundScore {
	rock = 1,
	paper = 2,
	scissors = 3,

	Loss = 0,
	Draw = 3,
	Win = 6
};

int checkResult(char opponent, char player)
{
	//convert to readable result
	int opponentResult{};
	int playerResult{};
	int matchResult{};

	switch (opponent)
	{
	case 'A':
		opponentResult = Rock;
		break;
	case 'B':
		opponentResult = Paper;
		break;
	case 'C':
		opponentResult = Scissors;
		break;
	}

	switch (player)
	{
	case 'X':
		playerResult = Rock;
		break;
	case 'Y':
		playerResult = Paper;
		break;
	case 'Z':
		playerResult = Scissors;
		break;
	}

	//compare
	if (playerResult == opponentResult)
		matchResult = (playerResult + 1) + Draw;
	else if (playerResult == Rock && opponentResult == Scissors)
		matchResult = rock + Win;
	else if (playerResult == Paper && opponentResult == Rock)
		matchResult = paper + Win;
	else if (playerResult == Scissors && opponentResult == Paper)
		matchResult = scissors + Win;
	else
		matchResult = (playerResult + 1) + Loss;

	return matchResult;
}

int main()
{
	ifstream input("../input.txt");
	string line;
	int totalScore = 0;

	// Check if the file was successfully opened
	if (!input.is_open())
	{
		cerr << "Failed to open input file!" << endl;
		return 1;
	}

	// Read each line of the file
	while (getline(input, line))
	{
		totalScore += checkResult(line[0], line[2]);
	}

	cout << "Score: " << totalScore << endl;

	// Close the file
	input.close();

	// Return success
	return 0;
}