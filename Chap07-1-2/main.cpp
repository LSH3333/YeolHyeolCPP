#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char * name;
    int age;
public:
    MyFriendInfo(char _name[], int _age)
    : age(_age)
    {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    void ShowMyFriendInfo()
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }

    ~MyFriendInfo()
    {
        delete name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char * addr;
    char * phone;
public:
    MyFriendDetailInfo(char _name[], int _age, char _addr[], char _phone[])
    : MyFriendInfo(_name, _age)
    {
        addr = new char[strlen(_addr) + 1];
        strcpy(addr, _addr);
        phone = new char[strlen(_phone) + 1];
        strcpy(phone, _phone);
    }

    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소: " << addr << endl;
        cout << "전화: " << phone << endl;
    }

    // 유도 클래스는 유도 클래스에서 동적 할당한 것만 해제하면 된다
    // 기초 클래스의 동적할당은 기초 클래스의 소멸자가 알아서 해제할것이기 때문
    ~MyFriendDetailInfo()
    {
        delete addr;
        delete phone;
    }
};

int main()
{
    MyFriendDetailInfo myFriendDetailInfo("Lee", 20, "Suwon", "010-1111-2222");
    myFriendDetailInfo.ShowMyFriendDetailInfo();
}