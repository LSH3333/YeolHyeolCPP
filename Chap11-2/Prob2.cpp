#include <iostream>
using namespace std;


class BoundCheckIntArray
{
private:
    int *arr;
    int arrlen;
    // 복사, 대입을 막기 위해 복사 생성자와 대입 연산자를 private 선언
    BoundCheckIntArray(const BoundCheckIntArray &arr) {}
    BoundCheckIntArray& operator= (const BoundCheckIntArray &arr) {}
public:
    BoundCheckIntArray(int len) : arrlen(len) { arr = new int[len]; }
    // const 없는 operator[]
    int& operator[] (int idx)
    {
        if(idx < 0 || idx >= arrlen)
        {
            cout << "Array idx out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    // const로 오버라이딩된 operator[]
    int operator[] (int idx) const
    {
        if(idx < 0 || idx >= arrlen)
        {
            cout << "Array idx out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const { return arrlen; }
    ~BoundCheckIntArray() { delete []arr; }
};

class BoundCheck2DIntArray
{
private:
    BoundCheckIntArray **arr;
    int arrlen;
    BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
    BoundCheck2DIntArray& operator= (const BoundCheck2DIntArray& arr) {}

public:
    BoundCheck2DIntArray(int c, int r) : arrlen(c)
    {
        arr = new BoundCheckIntArray*[c];
        for(int i = 0; i < c; i++)
            arr[i] = new BoundCheckIntArray(r);
    }
    BoundCheckIntArray& operator[] (int idx)
    {
        if(idx < 0 || idx >= arrlen)
        {
            cout << "Array idx out of bound exception" << endl;
            exit(1);
        }
        return *(arr[idx]);
    }
    ~BoundCheck2DIntArray()
    {
        for(int i = 0; i < arrlen; i++)
            delete arr[i];
        delete []arr;
    }
};

int main()
{
    BoundCheck2DIntArray arr2d(3, 4);

    for(int n = 0; n < 3; n++)
        for(int m = 0; m < 4; m++)
            arr2d[n][m] = n + m;

    for(int n = 0; n < 3; n++)
    {
        for(int m = 0; m < 4; m++)
        {
            cout << arr2d[n][m] << ' ';
        } cout << endl;
    }
}