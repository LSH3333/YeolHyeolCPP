#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition()
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

template <typename T>
void Swap(T &p1, T &p2)
{
    T temp = p1;
    p1 = p2;
    p2 = temp;
}
//
//int main()
//{
//    Point p1(1,2);
//    Point p2(3, 4);
//    Swap(p1, p2);
//    p1.ShowPosition();
//    p2.ShowPosition();
//}