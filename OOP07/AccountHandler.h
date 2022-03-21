#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

class AccountHandler
{
private:
    Account * accounts[100];
    int accNum;

public:
    AccountHandler();
    int PrintMenu();
    void MakeAccount();
    void MakeNormalAccount();
    void MakeHighCreditAccount();
    void Deposit();
    void WithDraw();
    void PrintAllAccountsInfo();
    ~AccountHandler();
};

#endif // __ACCOUNT_HANDLER__