#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream input("../input.txt");

	// Check if the file was successfully opened
	if (!input.is_open()) {
		cerr << "Failed to open input file!" << endl;
		return 1;
	}

	// Read each line of the file
	string line;
	int highestCalorieCount = 0;
	int previous = 0;
	int current = 0;
	while (getline(input, line))
	{

		//check previous count against highest so far
		if (line.empty())
		{
			previous = current;
			current = 0;
			if (previous > highestCalorieCount)
				highestCalorieCount = previous;
		}
		else // Add the value to the sum
		{
			// Convert the line to an integer
			int value = atoi(line.c_str());
			current += value;
		}
	}

	// Print the sum
	cout << "highest Calorie Count: " << highestCalorieCount << endl;

	// Close the file
	input.close();

	// Return success
	return 0;
}