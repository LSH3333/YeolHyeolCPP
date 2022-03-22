#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage) : age(myage)
    {
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
    }
    void ShowPersonInfo()
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    Person& operator= (const Person& ref)
    {
        // 이 객체의 name의 주소값은 새로 할당될 것이기 때문에 필요가 없다
        // 메모리 누수를 위해 이미 존재하는 주소값은 삭제한다
        delete[] name;
        age = ref.age;
        name = new char[strlen(ref.name)+1];
        strcpy(name, ref.name);
        return *this;
    }
    ~Person()
    {
        delete[] name;
        cout << "called Destructor" << endl;
    }
};
