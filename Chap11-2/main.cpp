#include <iostream>
#include <cstdlib>
using namespace std;


class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    friend ostream& operator<< (ostream& os, const Point& pos);
    friend ostream& operator<< (ostream &os, const Point* pos);
};

// Point&를 받아서 좌표 출력
ostream& operator<< (ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}
// Point* 받아서 포인터 타고가서 좌표 출력
ostream& operator<< (ostream &os, const Point* pos)
{
    os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
    return os;
}

typedef Point * POINT_PTR;

class BoundCheckPointPtrArray
{
private:
    POINT_PTR * arr; // double pointer
    int arrlen;
    // 복사 생성자, 대입 연산자 오버라이딩 금지
    BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) {}
    BoundCheckPointPtrArray& operator= (const BoundCheckPointPtrArray& arr) {}
public:
    BoundCheckPointPtrArray(int len) : arrlen(len)
    {
        arr = new POINT_PTR[len]; // 저장의 대상이 Point 객체의 주소값
    }
    POINT_PTR& operator[] (int idx)
    {
        if(idx < 0 || idx >= arrlen)
        {
            cout << "Array idx out of bound exception" <<endl;
            exit(1);
        }
        return arr[idx];
    }
    POINT_PTR operator[] (int idx) const
    {
        if(idx < 0 || idx >= arrlen)
        {
            cout << "Array idx out of bound exception" <<endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const { return arrlen; }
    ~BoundCheckPointPtrArray() {delete []arr; }
};

//
//
//int main()
//{
//    BoundCheckPointPtrArray arr(3);
//    arr[0] = new Point(3,4);
//    arr[1] = new Point(5,6);
//    arr[2] = new Point(7,8);
//
//    for(int i = 0; i < arr.GetArrLen(); i++)
//        cout << *(arr[i]);
//    cout << endl;
//
//    for(int i = 0; i < arr.GetArrLen(); i++)
//        cout << arr[i];
//    cout << endl;
//
//    delete arr[0];
//    delete arr[1];
//    delete arr[2];
//}
