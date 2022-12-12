#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

// !!fix the globals!!
int highestCalorieCount = 0;
int secondHighestCalorieCount = 0;
int thirdHighestCalorieCount = 0;

// check which place the value should go
void updateTop3(int value)
{
	if (value > highestCalorieCount)
		highestCalorieCount = value;
	else if (value > secondHighestCalorieCount)
		secondHighestCalorieCount = value;
	else
		thirdHighestCalorieCount = value;
}

int main()
{
	ifstream input("../input.txt");
	string line;
	int current = 0;
	int elfCount = 234;
	int elves[234];
	int i = 0;

	// Check if the file was successfully opened
	if (!input.is_open()) {
		cerr << "Failed to open input file!" << endl;
		return 1;
	}

	// Read each line of the file
	while (getline(input, line))
	{
		// until a new line is found, add to current value
		if (!line.empty())
		{
			// Convert the line to an integer and add to total
			int value = atoi(line.c_str());
			current += value;
		}
		else
		{
			elves[i] = current;
			i++;
			current = 0;
		}
	}

	sort(elves, elves + elfCount);

	int total = (elves[elfCount - 1] + elves[elfCount - 2] + elves[elfCount - 3]);
	cout << "total: " << total << endl;

	// Close the file
	input.close();

	// Return success
	return 0;
}