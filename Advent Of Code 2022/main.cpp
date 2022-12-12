#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

enum opponentHand {
	Rock,
	Paper,
	Scissors
};

enum gameResult {
	Win,
	Loss,
	Draw
};

enum roundScore {
	rock = 1,
	paper = 2,
	scissors = 3,

	loss = 0,
	draw = 3,
	win = 6
};

int checkResult(char opponent, char result)
{
	int opponentHand{};
	int playerHand{};
	int matchResult{};

	//convert opponent hand to readable result
	switch (opponent)
	{
	case 'A':
		opponentHand = Rock;
		break;
	case 'B':
		opponentHand = Paper;
		break;
	case 'C':
		opponentHand = Scissors;
		break;
	}

	//convert result to readable result
	switch (result)
	{
	case 'X':
		matchResult = Loss;
		break;
	case 'Y':
		matchResult = Draw;
		break;
	case 'Z':
		matchResult = Win;
		break;
	}

	//determine players hand based on rules
	if (matchResult == Loss)
	{
		switch (opponentHand)
		{
		case Rock:
			playerHand = Scissors;
			break;
		case Paper:
			playerHand = Rock;
			break;
		case Scissors:
			playerHand = Paper;
			break;
		}
	}
	else if (matchResult == Win)
	{
		switch (opponentHand)
		{
		case Rock:
			playerHand = Paper;
			break;
		case Paper:
			playerHand = Scissors;
			break;
		case Scissors:
			playerHand = Rock;
			break;
		}
	}
	else if (matchResult == Draw)
	{
		playerHand = opponentHand;
	}

	// define the score based
	if (playerHand == opponentHand)
		matchResult = (playerHand + 1) + draw;
	else if (playerHand == Rock && opponentHand == Scissors)
		matchResult = rock + win;
	else if (playerHand == Paper && opponentHand == Rock)
		matchResult = paper + win;
	else if (playerHand == Scissors && opponentHand == Paper)
		matchResult = scissors + win;
	else
		matchResult = (playerHand + 1) + loss;

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