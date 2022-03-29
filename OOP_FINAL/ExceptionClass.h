#ifndef OOP_FINAL_EXCEPTIONCLASS_H
#define OOP_FINAL_EXCEPTIONCLASS_H

#include <iostream>
using namespace std;

// 입출금 진행시 사용자로부터 0보다 작은 값이 입력되는 예외 상황
class NotAllowedInputException
{
private:
    int money;
public:
    NotAllowedInputException(int _money) : money(_money) {}
    void ShowExceptionInfo()
    {
        cout << "입출금 금액 " << money << "는 유효하지 않습니다" << endl;
    }
};

class NotEnoughBalanceException
{
private:
    int balance, money;
public:
    NotEnoughBalanceException(int _balance, int _money) : balance(_balance), money(_money) {}
    void ShowExceptionInfo()
    {
        cout << "현재 잔액은 " << balance << "입니다" << endl;
        cout << "요청하신 출금 금액은 " << money << "입니다" << endl;
    }
};

#endif //OOP_FINAL_EXCEPTIONCLASS_H
