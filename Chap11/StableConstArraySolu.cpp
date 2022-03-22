#include <iostream>
#include <cstring>
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

void ShowAllData(const BoundCheckIntArray& ref)
{
    int len = ref.GetArrLen();
    for(int i = 0; i < len; i++)
        // ref.operator[](i)이고 매개변수를 const 형으로 받았으므로
        // const 오버라이딩되어있는 operator[] 실행됨
        cout << ref[i] << endl;
}

int main()
{
    BoundCheckIntArray arr(5);
    for(int i = 0; i <5; i++)
        // const 아닌 arr을 이용한 연산이므로 const가 아닌 operator[] 실행
        arr[i] = (i + 1) * 11;
    ShowAllData(arr);
}