#include <iostream>
#include <string>;
using namespace std;

/*Overload Testing
int Add(int a, int b);
float Add(float a, float b);
double Add(double a, double b);*/

float Max(float n1, float n2, float n3);
bool IsEven(int num);
bool IsOdd(int num);
void AnalyzeNumber(int num, bool& isEven, bool& isOdd, bool& isZero, bool& isPositive, bool& isNegative);
int Power(int exponent, int base);
int Cubed(int num);
void PrintMessage(string message);

/*Overload Testing
void PrintMessage(string message, int num);
void PrintMessage(string message, float num);
void PrintMessage(string message, double num);*/

template <typename T>
T Add(T a, T b);

template <typename T, typename... Args>
T Add(T first, Args... args);

template <typename T>
void PrintMessage(string message, T num);



int main()
{
	/*
	int age;
	float weight;
	double distance;
	bool isAlive;
	char initial;
	string name;

	unsigned short int betterAge;
	long double hugeDistance;

	age = 26;
	weight = 190.5f;
	distance = 1212.987;
	isAlive = true;
	initial = 'K';
	name = "Kevin";

	//cout << "My name is " << name << " and I am " << age << " years old." << endl;
	//cout << "Am I alive: " << isAlive << endl;

	int newAge;
	newAge = age; // 26

	int newestAge = 27;


	int a = 10;
	int b = 3;

	int add = a + b;
	int subtract = a - b;
	int multiply = a * b;
	int division = a / b;
	int mod = a % b;

	float div2 = 10 / 3.0f;

	cout << div2 << endl;

	int result = 1 + (2 * 3) + 4; // 13 or 11
	cout << result << endl;
	

	int x = 10;
	x = x + 20; // These two are
	x += 20;	// the same

	x -= 10; // x = x - 10;
	x *= 10; // x = x * 10;
	x /= 10; // x = x / 10;
	x %= 10; // x = x % 10;
	

	float myFloat = 30.5f;
	int myInt = (int) myFloat;

	int a = 20;
	float b = (float) a;

	int result = (int) (2.4 + 1.6);

	cout << result << endl;
	

	/* Getting input */ /*
	//Prompt for Name
	cout << "Please enter your name: ";

	//Get Name
	string name;
	cin >> name;

	//Prompt user for year of birth
	cout << "What is your birth year: ";

	//Get YoB
	int yearOfBirth;
	cin >> yearOfBirth;

	//Prompt user for the current Year
	cout << "What is the current year: ";

	//Get the current year
	int currYear;
	cin >> currYear;

	//Display info to the user
	int age = currYear - yearOfBirth;
	cout << name << " you are " << age << " years old!" << endl;
	*/

	/*Celsius to Farenheit converter */ /*
	//Prompt user to enter temp in celsius
	cout << "Please enter the temprature in celcius: ";

	//Get Temp
	float celsius;
	cin >> celsius;

	//Convert Temp to fahrenheit
	float fahrenheit = (celsius * 9.0f) / 5.0f + 32;

	//display temps
	cout << celsius << " celsius in fehrenheit is " << fahrenheit << " fahrenheit" << endl;
	 
	*/
	
	/*cm to feet converter*/ /*
	// Prompt user to enter distance in cm
	cout << "Please enter a distance in centimeters: ";

	// Get cm
	int centimeters;
	cin >> centimeters;

	// Calculate Feet
	float totalFeet = centimeters / 30.48f;
	int justFeet = (int) totalFeet;

	// Calculate inches
	int justInches = (int) ((totalFeet - justFeet) * 12);

	// Display the conversion
	cout << "Feet = " << justFeet << endl;
	cout << "Inches = " << justInches << endl;
	*/

	/*Sum and Average of Three Numbers*//*
	
	//Prompt the user for three numbersand set numbers 
	cout << "Please enter number 1: ";
	int x;
	cin >> x;

	cout << "Please enter number 2: ";
	int y;
	cin >> y;

	cout << "Please enter number 3: ";
	int z;
	cin >> z;

	// Calculate the Sum
	int sum = x + y + z;
	
	// Calculate the Average
	float avg = sum / 3.0f;

	// Show user the sum and average
	cout << "The sum of your numbers is " << sum << " and the average is " << avg << endl;
	

	PrintMessage("Testing Add");
	PrintMessage("1 + 2 =");
	cout << Add(1, 2) << endl;

	PrintMessage("Testing Max");
	cout << "20.5, 30.5, 50.5, Max = " << Max(20.5f, 30.5f, 50.5f) << endl;

	PrintMessage("Testing Even/Odd");
	int num = 10;
	bool isEven = IsEven(num);
	bool isOdd = IsOdd(num);
	if (isEven)
		cout << num << " is even!" << endl;
	if (isOdd)
		cout << num << " is odd!" << endl;
	
	
	int num = 0;
	bool isEven = false, isOdd = false, isPositive = false, isNegative = false, isZero = false;

	AnalyzeNumber(num, isEven, isOdd, isZero, isPositive, isNegative);

	cout << "Analyzing Number: " << num << endl;
	string evenQuote = isEven ? "It's Even!\n" : "";
	string oddQoute = isOdd ? "It's Odd!\n" : "";
	string zeroQuote = isZero ? "It's Zero!\n" : "";
	string postiveQuote = isPositive ? "It's Positive!\n" : "";
	string negativeQuote = isNegative ? "It's Negative!\n" : "";

	cout << evenQuote << oddQoute << zeroQuote << postiveQuote << negativeQuote << endl;
	*/
	/*
	cout << Power(0, 3) << endl;
	cout << Power(1, 3) << endl;
	cout << Power(2, 3) << endl;
	cout << Power(3, 3) << endl;
	cout << Power(4, 3) << endl;
	cout << Power(5, 3) << endl;
	cout << Power(6, 3) << endl;
	cout << Power(7, 3) << endl;
	cout << Power(8, 3) << endl;
	*/
	/*
	int i = Add(1, 2, 3);
	float f = Add(3.3f, 6.6f, 5.5f, 2.7f);
	double d = Add(4.4, 2.4);

	PrintMessage("Testing Overload Functions:");
	PrintMessage("Integer Addition = ", i);
	PrintMessage("Float Addition = ", f);
	PrintMessage("Double Addition = ", d);
	*/

	// Prompt user for number
	cout << "Please enter number to be cubed: ";
	
	// Get Number
	int num;
	cin >> num;
	
	// Cube it
	int cubed = Cubed(num);
	
	// Give User answer
	cout << num << " cubed = " << cubed << endl;
}	

void PrintMessage(string message)
{
	cout << message << endl;
}

/*Overload Testing
void PrintMessage(string message, int num)
{
	cout << message << num << endl;
}

void PrintMessage(string message, float num)
{
	cout << message << num << endl;
}

void PrintMessage(string message, double num)
{
	cout << message << num << endl;
}
 */

template <typename T>
void PrintMessage(string message, T num)
{
	cout << message << num << endl;
}

/* Overload Testing 
int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}
*/

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

template <typename T, typename... Args>
T Add(T first, Args... rest)
{
	return first + Add(rest...);
}


float Max(float n1, float n2, float n3)
{
	float max = n1;
	if (n2 > max)
		max = n2;
	if (n3 > max)
		max = n3;

	return max;
}

bool IsEven(int num)
{
	if (num % 2 == 0)
		return true;
	return false;
}

bool IsOdd(int num)
{
	return !IsEven;
}

void AnalyzeNumber(int num, bool& isEven, bool& isOdd, bool& isZero, bool& isPositive, bool& isNegative)
{
	if (num % 2 == 0)
	{
		isEven = true;
		isOdd = false;
	}
	else
	{
		isEven = false;
		isOdd = true;
	}

	if (num > 0)
	{
		isPositive = true;
		isNegative = false;
		isZero = false;
	}
	else if (num < 0)
	{
		isPositive = false;
		isNegative = true;
		isZero = false;
	}
	else
	{
		isPositive = false;
		isNegative = false;
		isZero = true;
	}
}

int Power(int exponent, int base)
{
	if (exponent == 0)
	{
		return 1;
	}
	else
	{
		return base * Power(exponent - 1, base);
	}
}

int Cubed(int num)
{
	return num * num * num;
}
