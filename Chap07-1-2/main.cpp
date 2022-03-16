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
        cout << "�̸�: " << name << endl;
        cout << "����: " << age << endl;
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
        cout << "�ּ�: " << addr << endl;
        cout << "��ȭ: " << phone << endl;
    }

    // ���� Ŭ������ ���� Ŭ�������� ���� �Ҵ��� �͸� �����ϸ� �ȴ�
    // ���� Ŭ������ �����Ҵ��� ���� Ŭ������ �Ҹ��ڰ� �˾Ƽ� �����Ұ��̱� ����
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