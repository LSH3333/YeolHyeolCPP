
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
