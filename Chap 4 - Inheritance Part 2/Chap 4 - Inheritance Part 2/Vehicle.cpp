#include "Vehicle.h"

	Vehicle::Vehicle()
		:m_miles(0)
		,m_gas(0.0f)
	{
	}

	Vehicle::Vehicle(int miles, float gas)
		:m_miles(miles)
		,m_gas(gas)
	{
	}


	Car::Car()
		:Vehicle()
		,m_make("")
	{
	}

	Car::Car(int miles, float gas, string make)
		:Vehicle(miles, gas)
		,m_make(make)
	{
	}

	void Car::drive()
	{
		cout << "Vroom Vrom!" << endl;
	}

	Airplane::Airplane()
		:Vehicle()
		,m_altitude(0.0f)
	{
	}

	Airplane::Airplane(int miles, float gas, float altitude)
		:Vehicle(miles, gas)
		,m_altitude(altitude)
	{
	}

	void Airplane::drive()
	{
		cout << "Swoosh Swoosh!" << endl;
	}

	Boat::Boat()
		:Vehicle()
		, m_lat(0.0f)
		, m_long(0.0f)
	{
	}

	Boat::Boat(int miles, float gas, float lat, float lon)
		:Vehicle(miles, gas)
		,m_lat(lat)
		,m_long(lon)
	{
	}

	void Boat::drive()
	{
		cout << "Splash Splash!" << endl;
	}