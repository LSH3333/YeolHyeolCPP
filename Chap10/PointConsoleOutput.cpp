#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

    friend ostream& operator<< (ostream& os, const Point &pos);
};

//ostream& operator<< (ostream& cout, const Point &pos)
//{
//    cout << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
//    return cout;
//}

ostream& operator<< (ostream& os, const Point &pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

int main()
{
    Point pos1(1, 3);
    cout << pos1;
    Point pos2(3, 4);
    cout << pos2;
}