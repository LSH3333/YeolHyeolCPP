#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Account
{
    int accID; // ���¹�ȣ
    int balance; // �ܾ�
    string cusName; // �� �̸�
};

vector<Account> accounts;

// �޴� ���
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

// ���� ����
void MakeAccount()
{
    int accID, balance;
    string cusName;

    cout << "[���°���]\n";
    cout << "����ID: "; cin >> accID;

    cout << "�� ��: "; cin >> cusName;

    cout << "�Աݾ�: "; cin >> balance;

    Account account;
    account.accID = accID;
    account.balance = balance;
    account.cusName = cusName;
    accounts.push_back(account);
}

// �Ա�
void Deposit()
{
    int accID, balance;
    cout << "[��   ��]" << endl;
    cout << "����ID: "; cin >> accID;
    cout << "�Աݾ�: "; cin >> balance;
    cout << "�ԱݿϷ�" << endl;

    for(auto &acc : accounts)
    {
        if(acc.accID == accID)
        {
            acc.balance += balance;
            break;
        }
    }
}

// ���
void WithDraw()
{
    int accID, balance;
    cout << "[��   ��]" << endl;
    cout << "����ID: "; cin >> accID;
    cout << "��ݾ�: "; cin >> balance;
    cout << "��ݿϷ�" << endl;

    for(auto &acc : accounts)
    {
        if(acc.accID == accID)
        {
            acc.balance -= balance;
            break;
        }
    }
}

// ���� ���� ��ü ���
void PrintAllAccountsInfo()
{
    for(auto acc : accounts)
    {
        cout << "����ID: " << acc.accID << endl;
        cout << "�� ��: " << acc.cusName << endl;
        cout << "�� ��: " << acc.balance << endl << endl;
    }
}


int main()
{
    while(true)
    {
        int chose = PrintMenu();
        if(chose == 5) break;
        switch(chose)
        {
            case 1:
                MakeAccount(); break;
            case 2:
                Deposit(); break;
            case 3:
                WithDraw(); break;
            case 4:
                PrintAllAccountsInfo(); break;
            default:
                break;
        }
        cout << endl;
    }
}