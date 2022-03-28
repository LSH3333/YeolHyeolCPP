#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

// string to integer
int StoI(char *str)
{
    int len = strlen(str);
    int num = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] < '0' || str[i] > '9')
            throw str[i];
        num += (int)(pow((double)10, (len-1)-i) * (str[i]+(7-'7')));
    }
    return num;
}

int main()
{
    
}