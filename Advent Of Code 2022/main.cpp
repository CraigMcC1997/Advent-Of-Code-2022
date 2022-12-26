#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string elfGroup[3];
long int totalScore = 0;

void add_score(const char& c)
{
	// Found a repeated character, compute the score
	if (c >= 'a' && c <= 'z') {
		// Lowercase letter, score is 1 through 26
		totalScore += c - 'a' + 1;
	}
	else if (c >= 'A' && c <= 'Z') {
		// Uppercase letter, score is 27 through 52
		totalScore += c - 'A' + 27;
	}
}

void find_letter()
{
	char commonLetter = '\0';

	// Iterate over the characters in the first string
	for (char c1 : elfGroup[0])
	{
		// Initialize a counter variable
		int counter = 1;

		// Iterate over the characters in the second and third strings
		for (int i = 1; i < 3; i++) {
			// Check if the current character is present in the current string
			if (elfGroup[i].find(c1) != string::npos) {
				// Increment the counter if the character is found
				counter++;
			}
		}

		// Check if the character was found in all three strings
		if (counter == 3) {
			// Set the common letter if it was found in all three strings
			commonLetter = c1;
			break;
		}
	}

	cout << "Common Letter: " << commonLetter << endl;
	add_score(commonLetter);
}

int main()
{
	ifstream input("../input.txt");
	string line;
	int i = 0;

	// Check if the file was successfully opened
	if (!input.is_open())
	{
		cerr << "Failed to open input file!" << endl;
		return 1;
	}

	// store the elfs in groups of three
	while (getline(input, line))
	{
		//if group is full then check it for the "badge"
		if (i == 3)
		{
			find_letter();
			i = 0;
		}

		elfGroup[i] = line;
		i++;
	}

	// check if there are any lines left in the group
	if (i > 0) {
		find_letter();
	}

	cout << "Total Score: " << totalScore << endl;

	// Close file
	input.close();

	return 0;
}