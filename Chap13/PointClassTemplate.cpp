#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x = 0, T y = 0) : xpos(x), ypos(y) {}
    void ShowPosition()
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
};

//int main()
//{
////    Point pos1(3, 4); // 클래스 템플릿은 자료형 생략 불가
//    Point<int> pos1(3, 4); // 자료형 명시
//    pos1.ShowPosition();
//
//    Point<char> pos2('P', 'F');
//    pos2.ShowPosition();
//
//}