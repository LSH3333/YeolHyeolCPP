#ifndef OOP_FINAL_BOUNDCHECKARRAY_H
#define OOP_FINAL_BOUNDCHECKARRAY_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class BoundCheckArray
{
private:
    T * arr;
    int arrlen;
    // 복사생성자, 대입 연산자를 private에 선언함으로써 사용 막음
    BoundCheckArray(const BoundCheckArray &arr) {}
    BoundCheckArray& operator= (const BoundCheckArray &arr) {}

public:
    // 디폴트 크기 설정 안해주면 AccountHandler.cpp의 생성자에서 에러발생
    BoundCheckArray(int len=100);
    T& operator[] (int idx);
    T operator[] (int idx) const;
    int GetArrLen() const;
    ~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
    arr = new T[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[](int idx)
{
    if(idx < 0 || idx >= arrlen)
    {
        cout << "Array idx out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
    if(idx < 0 || idx >= arrlen)
    {
        cout << "Array idx out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const { return arrlen; }

template <typename T>
BoundCheckArray<T>::~BoundCheckArray<T>() { delete []arr; }

#endif //OOP_FINAL_BOUNDCHECKARRAY_H
