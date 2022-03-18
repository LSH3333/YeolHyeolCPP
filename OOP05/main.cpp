/*
 * ���� ������������ �Լ��� ��� �����ϰ� ��Ʈ�� Ŭ���� AccountHandler Ŭ���� �߰�
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

    // ���� ���� �����ϴ� ���� ������
    Account(const Account &copy) : accID(copy.accID), balance(copy.balance)
    {
        // ���Ӱ� ���� �Ҵ��ؼ� ���� ���� ����
        cusName = new char[strlen(copy.cusName) + 1];
        strcpy(cusName, copy.cusName);
    }

    int Get_accID() const
    {
        return accID;
    }

    void ShowAccInfo() const
    {
        cout << "����ID: " << accID << endl;
        cout << "�� ��: " << cusName << endl;
        cout << "�� ��: " << balance << endl << endl;
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
        cout << "1. ���°���" << endl;
        cout << "2. �� ��" << endl;
        cout << "3. �� ��" << endl;
        cout << "4. �������� ��ü ���" << endl;
        cout << "5. ���α׷� ����" << endl;
        cout << "����: ";
        int chose; cin >> chose;
        cout << endl;
        return chose;
    }

    void MakeAccount()
    {
        int accID, balance;
        char cusName[NAME_LEN];

        cout << "[���°���]\n";
        cout << "����ID: "; cin >> accID;
        cout << "�� ��: "; cin >> cusName;
        cout << "�Աݾ�: "; cin >> balance;

        // �������� ��ü ����
        accounts[accNum++] = new Account(accID, balance, cusName);
    }

    void Deposit()
    {
        int accID, balance;
        cout << "[��   ��]" << endl;
        cout << "����ID: "; cin >> accID;
        cout << "�Աݾ�: "; cin >> balance;
        cout << "�ԱݿϷ�" << endl;

        for(int i = 0; i < accNum; i++)
        {
            if(accounts[i]->Get_accID() == accID)
            {
                accounts[i]->DepositMoney(balance);
                return;
            }
        }
        cout << "�������� �ʴ� ����ID �Դϴ� " << endl;
    }

    void WithDraw()
    {
        int accID, balance;
        cout << "[��   ��]" << endl;
        cout << "����ID: "; cin >> accID;
        cout << "��ݾ�: "; cin >> balance;
        cout << "��ݿϷ�" << endl;

        for(int i = 0; i < accNum; i++)
        {
            if(accounts[i]->Get_accID() == accID)
            {
                if(accounts[i]->WithDrawMoney(balance) == -1)
                    cout << "�ܾ��� �����մϴ�" << endl;
                else cout << "��� �Ϸ�" << endl;
                return;
            }
        }
        cout << "�������� �ʴ� ����ID �Դϴ� " << endl;
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
