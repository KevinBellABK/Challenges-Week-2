#include <iostream>
using namespace std;


int main()
{
	cout << "Please enter the current year: ";
	int year;
	cin >> year;

	if (year % 4 == 0)
	{
		if (year % 100 == 0 && year % 400 != 0)
		{
			cout << year << " is not a leap year." << endl;
		}
		else
		{
			cout << year << " is a leap year!" << endl;
		}
	}
	else
	{
		cout << year << " is not a leap year." << endl;
	}
}
