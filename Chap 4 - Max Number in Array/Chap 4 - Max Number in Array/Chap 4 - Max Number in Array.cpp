#include <iostream>
using namespace std;

int main()
{
	int max = INT_MIN;
	int arr[10] = { };
	cout << "Enter 10 numbers to add to the array: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	cout << "Max = " << max << endl;
}
