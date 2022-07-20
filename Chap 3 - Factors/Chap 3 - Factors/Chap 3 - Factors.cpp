#include <iostream>
using namespace std;

int main()
{
	bool isValid = true;
	int num;
	do {
		cout << "Please enter a positive number you want the factors of: ";
		
		cin >> num;
		if (num < 1)
		{
			isValid = false;
			cout << "!Invalid number was entered!" << endl;
		}
		else
			isValid = true;
	} while (!isValid);

	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
			cout << i << " ";
	}
}