#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
protected:
	int m_miles;
	float m_gas;

public:
	Vehicle();

	Vehicle(int miles, float gas);

	virtual void drive() = 0;
};


class Car : public Vehicle
{
protected:
	string m_make;

public:
	Car();

	Car(int miles, float gas, string make);

	void drive();
};

class Airplane : public Vehicle
{
protected:
	float m_altitude;

public:
	Airplane();

	Airplane(int miles, float gas, float altitude);

	void drive();
};

class Boat : public Vehicle
{
protected:
	float m_lat;
	float m_long;

public:
	Boat();	

	Boat(int miles, float gas, float lat, float lon);

	void drive();
};
