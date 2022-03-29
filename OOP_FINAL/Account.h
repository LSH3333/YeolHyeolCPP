#ifndef OOP_FINAL_ACCOUNT_H
#define OOP_FINAL_ACCOUNT_H

#include "String.h"
#include "ExceptionClass.h"

// 가상함수가 있는 polymorphic class
class Account
{
private:
    int accID;
    int balance;
    String cusName;

public:
    Account(int _accID, int _balance, String _cusName);
    int Get_AccID() const;
    void ShowAccInfo() const;
    // DepositMoney() 함수는 Account 클래스를 상속받는 클래스들이 다른 방식으로 사용해야 하기 때문에 virtual
    // 함수가 가상함수로 선언되면 해당 함수 호출 시, 포인터의 자료형을 기반으로 호출대상을 정하지 않고,
    //포인터 변수가 실제로 가르키는 객체를 참조하여 호출함.
    virtual void DepositMoney(int amount); // 가상 함수
    int WithDrawMoney(int amount);
};


#endif //OOP_FINAL_ACCOUNT_H
