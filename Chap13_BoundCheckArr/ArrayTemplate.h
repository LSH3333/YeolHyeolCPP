/*
 * 클래스 템플릿은 헤더파일에 정의까지 포함해야한다
 * 아니면 메인 함수가 있는 파일에 헤더파일과 정의가 담긴 소스파일 둘다 include 해야한다
 */

#ifndef __ARRAY_TEMPLATE_H__
#define __ARRAY_TEMPLATE_H__

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
    BoundCheckArray(int len);
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

#endif // __ARRAY_TEMPLATE_H__