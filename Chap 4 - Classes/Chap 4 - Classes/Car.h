#pragma once
#include <string>

class Car
{
	// Member Variables
	int m_year;
	int m_miles;
	std::string m_brand;

public:
	// Constuctors
	Car();
	Car(int year, int miles, std::string brand);

	// Destructor
	~Car();

	// Member functions
	void Display();
	void Drive(int miles);
};