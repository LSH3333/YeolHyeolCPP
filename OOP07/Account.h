#ifndef __ACCOUNT__H__
#define __ACCOUNT__H__

class Account
{
private:
    int accID;
    int balance;
    char * cusName;

public:
    Account(int _accID, int _balance, char * _cusName);
    Account(const Account &copy);

    int Get_accID() const;
    void ShowAccInfo() const;
    virtual void DepositMoney(int amount);
    int WithDrawMoney(int amount);
    ~Account();
};


#endif // __ACCOUNT__H__
