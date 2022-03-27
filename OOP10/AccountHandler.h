/*
 * BoundCheckArray 템플릿 클래스 사용
 */

#ifndef __ACCOUNT_HANDLER__
#define __ACCOUNT_HANDLER__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
    // Account* 형의 BoundCheckArray 클래스 템플릿 사용
    BoundCheckArray<Account*> accounts;
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