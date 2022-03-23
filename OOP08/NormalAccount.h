#ifndef __NORMAL_ACCOUNT_H__
#define  __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
    int interest;
public:
    NormalAccount(int _accID, int _balance, char * _cusName, int _interest)
            : Account(_accID, _balance, _cusName), interest(_interest) {}

    virtual void DepositMoney(int amount)
    {
        Account::DepositMoney(amount + (int)(amount * (interest/100.0)));
    }
};


#endif //  __NORMAL_ACCOUNT_H__
