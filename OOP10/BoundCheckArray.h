/*
 * 기존의 BounCheckAccountPtrArray 클래스의 Account**를
 * 템플릿 클래스를 이용하도록 변경.
 */

#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class BoundCheckArray
{
private:
    T * arr;
    int arrlen;
    BoundCheckArray(const BoundCheckArray &arr) {}
    BoundCheckArray& operator= (const BoundCheckArray &arr) {}
public:
    BoundCheckArray(int len=100); // 디폴트 크기 100 안해주면 AccountHandler.cpp의 생성자에서 에러발생
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
T& BoundCheckArray<T>::operator[] (int idx)
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
BoundCheckArray<T>::~BoundCheckArray() { delete []arr; }

# endif // __BOUND_CHECK_ARRAY_H__