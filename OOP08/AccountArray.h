

#ifndef __ACCOUNTARRAY__
#define __ACCOUNTARRAY__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
    ACCOUNT_PTR * arr;
    int arrlen;
    // 복사 생성자, 대입 연산자 오버라이딩 호출 금지
    BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray &arr);
    BoundCheckAccountPtrArray& operator= (const BoundCheckAccountPtrArray &arr);

public:
    BoundCheckAccountPtrArray(int len=100); // default size 100
    ACCOUNT_PTR& operator[] (int idx);
    ACCOUNT_PTR  operator[] (int idx) const;
    int GetArrLen() const;
    ~BoundCheckAccountPtrArray();
};

#endif