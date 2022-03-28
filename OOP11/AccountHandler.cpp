/*
 * 입출금시 예외 처리
 */

#include "AccountHandler.h"
#include "BankingCommon.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"


AccountHandler::AccountHandler() : accNum(0) {}

int AccountHandler::PrintMenu()
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

void AccountHandler::MakeAccount()
{
    int choice;
    cout << "[계좌종류선택]" << endl;
    cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
    cout << "선택: "; cin >> choice;

    if(choice == NORMAL) MakeNormalAccount();
    else MakeHighCreditAccount();
}

void AccountHandler::MakeNormalAccount()
{
    int accID, balance, interest;
//    char cusName[NAME_LEN];
    String cusName;

    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌ID: "; cin >> accID;
    cout << "이 름: "; cin >> cusName;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interest;

    // 동적으로 객체 생성
    accounts[accNum++] = new NormalAccount(accID, balance, cusName, interest);
}

void AccountHandler::MakeHighCreditAccount()
{
    int accID, balance, interest, rating;
//    char cusName[NAME_LEN];
    String cusName;

    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌ID: "; cin >> accID;
    cout << "이 름: "; cin >> cusName;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interest;
    cout << "신용등급(1toA, 2toB, 3toC): "; cin >> rating;

    accounts[accNum++] = new HighCreditAccount(accID, balance, cusName, interest, rating);
}

void AccountHandler::Deposit()
{
    int accID, balance;
    cout << "[입   금]" << endl;
    cout << "계좌ID: "; cin >> accID;

    while(true)
    {
        try
        {
            cout << "입금액: "; cin >> balance;

            for(int i = 0; i < accNum; i++)
            {
                if(accounts[i]->Get_accID() == accID)
                {
                    accounts[i]->DepositMoney(balance);
                    cout << "입금완료" << endl;
                    return;
                }
            }
            cout << "존재하지 않는 계좌ID 입니다 " << endl;
        }
        catch (NotAllowedInputException &expn) // 0보다 작은 값 입력 시
        {
            expn.ShowExceptionInfo();
        }
    }

}

void AccountHandler::WithDraw()
{
    int accID, balance;
    cout << "[출   금]" << endl;
    cout << "계좌ID: "; cin >> accID;

    while(true)
    {
        try
        {
            cout << "출금액: "; cin >> balance;

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
        catch (NotAllowedInputException &expn) // 0보다 작은 값 입력 시
        {
            expn.ShowExceptionInfo();
        }
        catch (NotEnoughBalanceException &expn) // 예금액 부족시
        {
            expn.ShowExceptionInfo();
        }
    }

}

void AccountHandler::PrintAllAccountsInfo()
{
    for(int i = 0; i < accNum; i++)
    {
        accounts[i]->ShowAccInfo();
    }
}

AccountHandler::~AccountHandler()
{
    for(int i = 0; i < accNum; i++) delete accounts[i];
}




