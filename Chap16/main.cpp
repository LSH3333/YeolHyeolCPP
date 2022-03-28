#include <iostream>
using namespace std;

class Car
{

};

class Truck : public Car
{

};

int main()
{
    Car *pcar1 = new Truck();
}