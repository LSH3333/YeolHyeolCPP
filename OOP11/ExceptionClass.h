#ifndef __EXCEPTION_CLASS_H__
#define __EXCEPTION_CLASS_H__

// 입출금 진행 시 사용자로 부터 0보다 작은 값이 입력되는 예외 상황
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

// 출금 시 예금된 금액보다 더 많은 금액의 출금을 요구하는 예외 상황
class NotEnoughBalanceException
{
private:
    int balance;
    int money;
public:
    NotEnoughBalanceException(int _balance, int _money) : balance(_balance), money(_money) {}
    void ShowExceptionInfo()
    {
        cout << "현재 잔액은 " << balance << "입니다" << endl;
        cout << "요청하신 출금 금액은 " << money << "입니다" << endl;
    }
};


#endif // __EXCEPTION_CLASS_H__