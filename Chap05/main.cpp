#include <iostream>
using namespace std;

class Person
{
private:
    char * name;
    int age;

public:
    Person(const Person &person)
    {
        age = person.age;
        name = new char[strlen(person.name) + 1];
        strcpy(name, person.name);
    }
};

int main() {

}
