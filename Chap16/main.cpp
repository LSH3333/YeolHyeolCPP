#include <iostream>
using namespace std;

class Car
{
private:
    int fuelGauge;
public:
    Car(int fuel) : fuelGauge(fuel) {}
    void ShowCarState() { cout << "잔여 연료량: " << fuelGauge << endl; }
};

class Truck : public Car
{
private:
    int freightWeight;
public:
    Truck(int fuel, int weight) : Car(fuel), freightWeight(weight) {}
    void ShowTruckState()
    {
        ShowCarState();
        cout << "화물의 무게: " << freightWeight << endl;
    }
};

void ShowString(char *str)
{
    cout << str << endl;
}

// Polymorphic 클래스
class SoSimple
{
public:
    virtual void ShowSimpleInfo() // 가상함수
    {
        cout << "SoSimple Class" << endl;
    }
};

class SoComplex : public SoSimple
{
public:
    void ShowSimpleInfo() // 오버라이딩된 가상함수는 자동으로 가상함수
    {
        cout << "SoComplex Derived Class" << endl;
    }
};

int main()
{
    SoSimple *simPtr = new SoComplex;
    SoComplex *comPtr = dynamic_cast<SoComplex*>(simPtr);
    comPtr->ShowSimpleInfo();
}