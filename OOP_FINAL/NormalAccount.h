#ifndef OOP_FINAL_NORMALACCOUNT_H
#define OOP_FINAL_NORMALACCOUNT_H

#include "Account.h"

class NormalAccount : public Account
{
private:
    int interest;
public:
    NormalAccount(int _accID, int _balance, String _cusName, int _interest)
    : Account(_accID, _balance, _cusName), interest(_interest)
    {}

    virtual void DepositMoney(int amount)
    {
        if(amount < 0) throw NotAllowedInputException(amount);
        Account::DepositMoney(amount + (int)(amount * (interest/100.0)));
    }
};

#endif //OOP_FINAL_NORMALACCOUNT_H
