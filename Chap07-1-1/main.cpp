#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    int gasolineGauge;

public:
    Car(int _gasolineGauge) : gasolineGauge(_gasolineGauge)
    {}

    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;

public:
    HybridCar(int _gasolineGauge, int _electricGauge)
    : Car(_gasolineGauge), electricGauge(_electricGauge)
    {}

    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int _gasolineGauge, int _electricGauge, int _waterGauge)
    : HybridCar(_gasolineGauge, _electricGauge), waterGauge(_waterGauge)
    {}

    void ShowCurrentGauge()
    {
        cout << "잔여 가솔린: " << GetGasGauge() << endl;
        cout << "잔여 전기량: " << GetElecGauge() << endl;
        cout << "잔여 워터량: " << waterGauge << endl;
    }
};

int main()
{
    HybridWaterCar hybridWaterCar(10, 20, 30);
    hybridWaterCar.ShowCurrentGauge();
}