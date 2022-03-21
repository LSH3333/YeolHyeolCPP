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

    // 증가된 맴버변수를 갖는 객체의 주소값 반환
    Point& operator+=(const Point &ref)
    {
        xpos += ref.xpos;
        ypos += ref.ypos;
        return *this;
    }

    Point& operator-=(const Point &ref)
    {
        xpos -= ref.xpos;
        ypos -= ref.ypos;
        return *this;
    }


};
