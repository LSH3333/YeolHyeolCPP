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

    NameCard(const NameCard &copy) : rank(copy.rank)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
        company = new char[strlen(copy.company) + 1];
        strcpy(company, copy.company);
        phoneNumber = new char[strlen(copy.phoneNumber) + 1];
        strcpy(phoneNumber, copy.phoneNumber);
    }

    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << company << endl;
        cout << "전화번호: " << phoneNumber << endl;
        cout << "직급: "; COMP_POS::ShowRank(rank);
        cout << endl;
    }

    ~NameCard()
    {
        delete name;
        delete company;
        delete phoneNumber;
        cout << "소멸자 실행" << endl;
    }
};

int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;

    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;

    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

}