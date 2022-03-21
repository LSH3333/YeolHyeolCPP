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


    friend bool operator==(const Point &pos1, const Point &pos2);
};

bool operator==(const Point &pos1, const Point &pos2)
{
    if(pos1.xpos == pos2.xpos && pos1.xpos == pos2.ypos) return true;
    return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    // 위에서 정의한 operator== 를 이용
    if(pos1 == pos2) return false;
    return true;
}


