/*
 * BoundCheckAccountPtrArray 적용
 */

#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
    // 기존의 Account* 형에서 변경
    BoundCheckAccountPtrArray accounts;
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