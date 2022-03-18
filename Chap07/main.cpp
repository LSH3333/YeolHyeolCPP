#include <iostream>
using namespace std;

class Base
{
private:
    int num1;
protected:
    int num2;
public:
    int num3;
};

class Derived : protected Base
{

};

int main()
{
    
}
