#include <iostream>
#include "Car.h"
using namespace std;

int main()
{
    Car myCar(2018, 300, "BMW");
    myCar.Display();
    myCar.Drive(200);
    myCar.Display();
}
