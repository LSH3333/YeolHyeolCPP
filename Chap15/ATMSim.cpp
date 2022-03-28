#include <iostream>
using namespace std;

class AccountException
{
public:
    virtual void ShowExceptionReason() = 0; // 순수 가상 함수
};

// 입금 예외, AccountException 클래스 상속함
class DepositException : public AccountException
{
private:
    int reqDep;
public:
    DepositException(int money) : reqDep(money) {}
    void ShowExceptionReason() override
    {
        cout << "[에외 메시지: " << reqDep << "는 입금불가]" << endl;
    }
};


// 출금 예외, AccountException 클래스 상속함
class WithdrawException : public AccountException
{
private:
    int balance;
public:
    WithdrawException(int money) : balance(money) {}
    void ShowExceptionReason()
    {
        cout << "[에외 메시지: 잔액 " << balance << " 잔액부족]" << endl;
    }
};

class Account
{
private:
    char accNum[50];
    int balance;
public:
    Account(char *acc, int money) : balance(money)
    {
        strcpy(accNum, acc);
    }

    // AccountException형 객체 throw 한다
    // DepositException 클래스는 AccountException 클래스를 상속받았기에 가능
    void Deposit(int money) throw (AccountException)
    {
        if(money < 0)
        {
            // 예외객체는 c++의 예외처리 메커니즘에 의해 처리되기 때문에 코드상에서 이를 직접 참조할 필요 없음
            // 따라서 예외 객체는 보통 임시객체로 생성한다.
            throw DepositException(money);
        }
        balance += money;
    }
    // 마찬가지로 AccountException형 객체 throw
    void Withdraw(int money) throw (AccountException)
    {
        if(money > balance)
            throw WithdrawException(balance);
        balance -= money;
    }

    void ShowMyMoney()
    {
        cout << "잔고: " << balance << endl << endl;
    }
};

int main()
{
    Account myAcc("123-123", 5000);

    try
    {
        myAcc.Deposit(2000);
        myAcc.Deposit(-300);
    }
    // 여기서 실제 전달되는 예외객체는 DepositException 혹은 WithdrawException 이지만
    // 해당 클래스는 AccountException 클래스를 상속받았기 때문에 이와 같이 표현 가능하다
    catch (AccountException &expn)
    {
        expn.ShowExceptionReason();
    }

    myAcc.ShowMyMoney();
}