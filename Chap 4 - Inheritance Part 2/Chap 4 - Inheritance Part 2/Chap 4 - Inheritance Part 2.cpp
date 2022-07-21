#include <iostream>
#include "Vehicle.h"

int main()
{
    Car* myCar = new Car(150000, 84.6f, "Hyundai");
    Airplane* deltaAirBus = new Airplane(900000, 15.4f, 0.0f);
    Boat* ssLevelUp = new Boat(450000, 96.2f, 37.1f, -125.2f);

    myCar->drive();
    deltaAirBus->drive();
    ssLevelUp->drive();
}