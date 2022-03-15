#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y): xpos(x), ypos(y) {}

    void ShowPointInfo() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }

    int GetX() const
    {
        return xpos;
    }

    int GetY() const
    {
        return ypos;
    }
};

class Circle
{
private:
    Point center;
    int rad;

public:
    Circle(Point _center, int _rad)
    : center(_center), rad(_rad) {}

    void ShowCircleInfo() const
    {
        cout << "radius: " << rad << endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle innerCircle;
    Circle outterCircle;

public:
    Ring(int innerX, int innerY, int innerRad, int outterX, int outterY, int outterRad)
    : innerCircle(Point(innerX, innerY), innerRad), outterCircle(Point(outterX, outterY), outterRad) {}

    void ShowRingInfo()
    {
        cout << "Inner Circle Info..." << endl;
        innerCircle.ShowCircleInfo();
        cout << "Outter Circle Info..." << endl;
        outterCircle.ShowCircleInfo();
    }
};

int main()
{
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
}