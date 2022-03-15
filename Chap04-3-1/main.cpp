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
    Circle(int x, int y, int _rad, Point center)
    : center(Point(x,y)), rad(_rad)
    {}

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

    void ShowRingInfo()
    {
        cout << "Inner Circle Info..." << endl;
        innerCircle.ShowCircleInfo();
        cout << "Outter Circle Info..." << endl;
        outterCircle.ShowCircleInfo();
    }
};

//int main()
//{
//    Ring ring;
//    ring.Init(1, 1, 4, 2, 2, 9);
//    ring.ShowRingInfo();
//}