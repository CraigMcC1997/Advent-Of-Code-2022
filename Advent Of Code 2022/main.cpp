#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void split_string(const string& input, string& first, string& second, const char c) {
	size_t index = input.find(c);
	if (index != string::npos) {
		first = input.substr(0, index);
		second = input.substr(index + 1);
	}
}

void check_overlap(const string& first, const string& second, int& numOverlaps)
{
	string s1, s2, s3, s4;
	int i1, i2, i3, i4;
	char c = '-';

	split_string(first, s1, s2, c);
	split_string(second, s3, s4, c);

	i1 = stoi(s1);
	i2 = stoi(s2);
	i3 = stoi(s3);
	i4 = stoi(s4);

	if (((i3 <= i1) && (i4 >= i2)) || ((i1 <= i3) && (i2 >= i4)))
	{
		numOverlaps++;
	}
}

int main()
{
	ifstream input("../input.txt");
	string line;
	int totalOverlaps = 0;
	string s1, s2;
	char c = ',';

	// Check if the file was successfully opened
	if (!input.is_open())
	{
		cerr << "Failed to open input file!" << endl;
		return 1;
	}

	// store the elfs in groups of three
	while (getline(input, line))
	{
		split_string(line, s1, s2, c);
		check_overlap(s1, s2, totalOverlaps);
	}

	cout << "Total Overlap: " << totalOverlaps << endl;

	// Close file
	input.close();

	return 0;
}