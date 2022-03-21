#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base Constructor" << endl; }
    void SimpleFunc() { cout << "BaseOne" << endl; }
};

class Mid1 : virtual public Base // Base를 가상상속
{
public:
    Mid1() : Base()
    {
        cout << "Mid1 Constructor" << endl;
    }
    void MiddleFuncOne()
    {
        SimpleFunc(); // base class의 맴버
        cout << "Mid1" << endl;
    }
};

class Mid2 : virtual public Base
{
public:
    Mid2() : Base()
    {
        cout << "Mid2 Constructor" << endl;
    }
    void MiddleFuncTwo()
    {
        SimpleFunc();
        cout << "Mid2" << endl;
    }
};

class Last: public Mid1, public Mid2
{
public:
    Last() : Mid1(), Mid2()
    {
        cout << "Last Constructor" << endl;
    }
    void ComplexFunc()
    {
        MiddleFuncOne();
        MiddleFuncTwo();
        // Mid1, Mid2가 Base를 가상상속 했으므로 Last에는 Base의 맴버가 하나씩만 존재한다
        SimpleFunc();
    }
};

int main()
{
    cout << "객체생성 전 ... " << endl;
    Last last;
    cout << "객체생성 후 ... " << endl;
    last.ComplexFunc();
}