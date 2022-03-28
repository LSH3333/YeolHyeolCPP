
#include "AccountHandler.h"
#include "BankingCommon.h"


int main()
{
    AccountHandler accHandler;
    while(true)
    {
        int chose = accHandler.PrintMenu();
        switch(chose)
        {
            case MAKE:
                accHandler.MakeAccount(); break;
            case DEPOSIT:
                accHandler.Deposit(); break;
            case WITHDRAW:
                accHandler.WithDraw(); break;
            case INQUIRE:
                accHandler.PrintAllAccountsInfo(); break;
            case EXIT:
                return 0;
        }
        cout << endl;
    }
}
