// Account 클래스 깊은 복사 진행하는 대입 연산자 오버로딩 추가

#include "BankingCommon.h"
#include "Account.h"

Account::Account(int _accID, int _balance, char * _cusName)
        : accID(_accID), balance(_balance)
{
    cusName = new char[strlen(_cusName)+1];
    strcpy(cusName, _cusName);
}

// 깊은 복사 진행하는 복사 생성자
Account::Account(const Account &copy) : accID(copy.accID), balance(copy.balance)
{
    // 새롭게 동적 할당해서 깊은 복사 진행
    cusName = new char[strlen(copy.cusName) + 1];
    strcpy(cusName, copy.cusName);
}

// 깊은 복사 진행하는 대입 연산자 오버로딩
Account& Account::operator= (const Account& ref)
{
    accID = ref.accID;
    balance = ref.balance;
    delete []cusName;
    cusName = new char[strlen(ref.cusName) + 1];
    strcpy(cusName, ref.cusName);
    return *this;
}

int Account::Get_accID() const { return accID; }

void Account::ShowAccInfo() const
{
    cout << "계좌ID: " << accID << endl;
    cout << "이 름: " << cusName << endl;
    cout << "잔 액: " << balance << endl << endl;
}

void Account::DepositMoney(int amount) // virtual
{
    balance += amount;
}

int Account::WithDrawMoney(int amount)
{
    if(balance < amount)
    {
        return -1;
    }
    balance -= amount;
    return balance;
}

Account::~Account()
{
    delete cusName;
}

