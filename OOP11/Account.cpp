/*
 * 예외 발생
 */

#include "BankingCommon.h"
#include "Account.h"
#include "ExceptionClass.h"

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
    // 0 미만 값 입력시 예외 발생
    if(amount < 0) throw NotAllowedInputException(amount);
    balance += amount;
}

int Account::WithDrawMoney(int amount)
{
    if(amount < 0) throw NotAllowedInputException(amount);
    // 입금 금액보다 큰 금액 출금 시도 시 예외 발생
    if(balance < amount) throw NotEnoughBalanceException(balance, amount);

    balance -= amount;
    return balance;
}



