#ifndef OOP_FINAL_HIGHCREDITACCOUNT_H
#define OOP_FINAL_HIGHCREDITACCOUNT_H

#include "NormalAccount.h"

// Account를 상속하는 NormalAccount를 상속하는 HighCreditAccount 클래스
class HighCreditAccount : public NormalAccount
{
private:
    int rating; // 신용등급
public:
    HighCreditAccount(int _accID, int _balance, String _cusName, int _interest, int _rating)
    : NormalAccount(_accID, _balance, _cusName, _interest), rating(_rating) {}

    virtual void DepositMoney(int amount)
    {
        if(amount < 0) throw NotAllowedInputException(amount);
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

#endif //OOP_FINAL_HIGHCREDITACCOUNT_H
