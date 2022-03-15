#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum { CLERK, SENIOR, ASSIST, MANAGER };

    void ShowRank(int _rank)
    {
        switch(_rank)
        {
            case CLERK:
                cout << "사원" << endl;
                break;
            case SENIOR:
                cout << "주임" << endl;
                break;
            case ASSIST:
                cout << "대리" << endl;
                break;
            case MANAGER:
                cout << "과장" << endl;
                break;
        }
    }
}

class NameCard
{
private:
    char * name;
    char * company;
    char * phoneNumber;
    int rank;

public:
    NameCard(char * _name, char * _company, char * _phoneNumber, int _rank) : rank(_rank)
    {
        name = new char[strlen(_name)+1];
        strcpy(name, _name);

        company = new char[strlen(_company)+1];
        strcpy(company, _company);

        phoneNumber = new char[strlen(_phoneNumber)+1];
        strcpy(phoneNumber, _phoneNumber);
    }

    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << company << endl;
        cout << "전화번호: " << phoneNumber << endl;
        cout << "직급: "; COMP_POS::ShowRank(rank);
    }

    ~NameCard()
    {
        delete name;
        delete company;
        delete phoneNumber;
    }
};

int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
}