#include <iostream>
using namespace std;

class Car
{
private:
    int fuelGauge;
public:
    Car(int fuel) : fuelGauge(fuel) {}
    void ShowCarState() { cout << "�ܿ� ���ᷮ: " << fuelGauge << endl; }
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
        cout << "ȭ���� ����: " << freightWeight << endl;
    }
};

void ShowString(char *str)
{
    cout << str << endl;
}

// Polymorphic Ŭ����
class SoSimple
{
public:
    virtual void ShowSimpleInfo() // �����Լ�
    {
        cout << "SoSimple Class" << endl;
    }
};

class SoComplex : public SoSimple
{
public:
    void ShowSimpleInfo() // �������̵��� �����Լ��� �ڵ����� �����Լ�
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