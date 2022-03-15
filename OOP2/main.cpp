#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN = 20;


enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Accout
{
private:
    int accID;
    int balance;
    char * cusName;
};