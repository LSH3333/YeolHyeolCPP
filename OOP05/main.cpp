/*
 * 기존 전역변수였던 함수들 모두 제거하고 컨트롤 클래스 AccountHandler 클래스 추가
 */

#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
    int accID;
    int balance;
    char * cusName;

public:
    Account(int _accID, int _balance, char * _cusName)
            : accID(_accID), balance(_balance)
    {
        cusName = new char[strlen(_cusName)+1];
        strcpy(cusName, _cusName);
    }

    // 깊은 복사 진행하는 복사 생성자
    Account(const Account &copy) : accID(copy.accID), balance(copy.balance)
    {
        // 새롭게 동적 할당해서 깊은 복사 진행
        cusName = new char[strlen(copy.cusName) + 1];
        strcpy(cusName, copy.cusName);
    }

    int Get_accID() const
    {
        return accID;
    }

    void ShowAccInfo() const
    {
        cout << "계좌ID: " << accID << endl;
        cout << "이 름: " << cusName << endl;
        cout << "잔 액: " << balance << endl << endl;
    }

    void DepositMoney(int amount)
    {
        balance += amount;
    }

    int WithDrawMoney(int amount)
    {
        if(balance < amount)
        {
            return -1;
        }
        balance -= amount;
        return balance;
    }

    ~Account()
    {
        delete cusName;
    }
};

class AccountHandler
{
private:
    Account * accounts[100];
    int accNum;

public:
    AccountHandler() : accNum(0) {}

    int PrintMenu()
    {
        cout << "----- MENU -----" << endl;
        cout << "1. 계좌개설" << endl;
        cout << "2. 입 금" << endl;
        cout << "3. 출 금" << endl;
        cout << "4. 계좌정보 전체 출력" << endl;
        cout << "5. 프로그램 종료" << endl;
        cout << "선택: ";
        int chose; cin >> chose;
        cout << endl;
        return chose;
    }

    void MakeAccount()
    {
        int accID, balance;
        char cusName[NAME_LEN];

        cout << "[계좌개설]\n";
        cout << "계좌ID: "; cin >> accID;
        cout << "이 름: "; cin >> cusName;
        cout << "입금액: "; cin >> balance;

        // 동적으로 객체 생성
        accounts[accNum++] = new Account(accID, balance, cusName);
    }

    void Deposit()
    {
        int accID, balance;
        cout << "[입   금]" << endl;
        cout << "계좌ID: "; cin >> accID;
        cout << "입금액: "; cin >> balance;
        cout << "입금완료" << endl;

        for(int i = 0; i < accNum; i++)
        {
            if(accounts[i]->Get_accID() == accID)
            {
                accounts[i]->DepositMoney(balance);
                return;
            }
        }
        cout << "존재하지 않는 계좌ID 입니다 " << endl;
    }

    void WithDraw()
    {
        int accID, balance;
        cout << "[출   금]" << endl;
        cout << "계좌ID: "; cin >> accID;
        cout << "출금액: "; cin >> balance;
        cout << "출금완료" << endl;

        for(int i = 0; i < accNum; i++)
        {
            if(accounts[i]->Get_accID() == accID)
            {
                if(accounts[i]->WithDrawMoney(balance) == -1)
                    cout << "잔액이 부족합니다" << endl;
                else cout << "출금 완료" << endl;
                return;
            }
        }
        cout << "존재하지 않는 계좌ID 입니다 " << endl;
    }

    void PrintAllAccountsInfo()
    {
        for(int i = 0; i < accNum; i++)
        {
            accounts[i]->ShowAccInfo();
        }
    }

    ~AccountHandler()
    {
        for(int i = 0; i < accNum; i++) delete accounts[i];
    }
};

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
