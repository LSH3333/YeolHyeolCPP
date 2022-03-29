#ifndef OOP_FINAL_ACCOUNTHANDLER_H
#define OOP_FINAL_ACCOUNTHANDLER_H

#include "Account.h"
#include "ExceptionClass.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
    // Account* 형의 BoundCheckArray class template 사용
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


#endif //OOP_FINAL_ACCOUNTHANDLER_H
