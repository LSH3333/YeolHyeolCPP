
#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
    int rating; // 신용등급
public:
    HighCreditAccount(int _accID, int _balance, char * _cusName, int _interest, int _rating)
            : NormalAccount(_accID, _balance, _cusName, _interest), rating(_rating) {}

    virtual void DepositMoney(int amount)
    {
        int additional_interest;
        switch(this->rating)
        {
            case A_RATING:
                additional_interest = (int)(amount * (7/100.0)); break;
            case B_RATING:
                additional_interest = (int)(amount * (4/100.0)); break;
            case C_RATING:
                additional_interest = (int)(amount * (2/100.0)); break;
        }
        NormalAccount::DepositMoney(amount); // 원금 + 이자
        Account::DepositMoney(additional_interest);
    }
};


#endif // __HIGH_CREDIT_ACCOUNT_H__
