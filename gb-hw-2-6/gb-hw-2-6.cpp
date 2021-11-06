#include <iostream>
#include <regex>
#include <string>

using namespace std;

ostream& endll(ostream& output) {
	output << endl << endl;
	return output;
}

int main()
{
	string str;
	cmatch result;
	regex regular("^[0-9]+$");
	int key = 0;

	cout << "1 task" << endl;
	cout << "input int: " << endl;
	do
	{
		if (key == 1)
		{
			cout << "Error! Input again " << endl;
		}
		cin >> str;
		key = 1;

	} while (!regex_match(str.c_str(), result, regular));

	cout << "2 task" << endl;
	cout << "check 1" << endll << "check 2" << endl;
	return 0;
}

