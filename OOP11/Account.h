// 고객이름 저장 방식을 char * 동적할당에서 String 클래스로 대체
// => String 클래스에서 정의되어 있으므로, Account 클래스에서의 소멸자, 복사 생성자, 대입 연산자 모두 제거

#ifndef __ACCOUNT__H__
#define __ACCOUNT__H__

#include "String.h"

class Account
{
private:
    int accID;
    int balance;
//    char * cusName;
    String cusName;

public:
    Account(int _accID, int _balance, String _cusName);

    int Get_accID() const;
    void ShowAccInfo() const;
    virtual void DepositMoney(int amount);
    int WithDrawMoney(int amount);
};


#endif // __ACCOUNT__H__
