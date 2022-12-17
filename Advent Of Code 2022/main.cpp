#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int split_string(const string& s)
{
	// Find the midpoint of the string
	size_t mid = s.length() / 2;

	// Get the first and second half of the string
	std::string first_half = s.substr(0, mid);
	std::string second_half = s.substr(mid);

	// Search for repeated characters
	for (char c : first_half) {
		if (second_half.find(c) != std::string::npos) {
			// Found a repeated character, compute the score
			if (c >= 'a' && c <= 'z') {
				// Lowercase letter, score is 1 through 26
				return c - 'a' + 1;
			}
			else if (c >= 'A' && c <= 'Z') {
				// Uppercase letter, score is 27 through 52
				return c - 'A' + 27;
			}
			else {
				// Non-letter character, score is 0
				return 0;
			}
		}
	}

	// No repeated characters found, score is 0
	return 0;
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
		totalScore += split_string(line);
	}

	cout << "total Score: " << totalScore << endl;

	// Close file
	input.close();

	return 0;
}