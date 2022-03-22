#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

    friend ostream& operator<< (ostream& os, const Point &pos);
    friend istream& operator>> (istream& is, Point &pos);
};

// output
ostream& operator<< (ostream& os, const Point &pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return cout;
}
// input
istream& operator>> (istream& is, Point &pos)
{
    is >> pos.xpos >> pos.ypos;
    return is;
}

int main()
{
    Point pos1;
    cout << "x,y 좌표 순으로 입력: ";
    cin >> pos1;
    cout << pos1;
}