#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << "[" << xpos << ',' << ypos << "]" << endl;
    }

    friend Point operator~ (const Point &ref);
};

Point operator~ (const Point &ref)
{
    Point pos(ref.ypos, ref.xpos);
    return pos;
}

int main()
{
    Point pos1(1,3);
    Point pos2 = ~pos1;
    pos2.ShowPosition();
}