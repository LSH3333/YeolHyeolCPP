
#include "BankingCommon.h"
#include "Account.h"

Account::Account(int _accID, int _balance, String _cusName)
        : accID(_accID), balance(_balance)
{
    cusName = _cusName;
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



