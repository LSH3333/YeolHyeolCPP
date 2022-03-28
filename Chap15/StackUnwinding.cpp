#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

// string to integer
int StoI(char *str)
{
    int len = strlen(str);
    int num = 0;

    // int형 throw
    if(len != 0 && str[0] == '0') throw 0;

    for(int i = 0; i < len; i++)
    {
        // char 형 throw
        if(str[i] < '0' || str[i] > '9') throw str[i];
        num += (int)(pow((double)10, (len-1)-i) * (str[i]+(7-'7')));
    }
    return num;
}

//int main()
//{
//    char str1[100];
//    char str2[200];
//
//    while(true)
//    {
//        cout << "두 개의 숫자 입력 ";
//        cin >> str1 >> str2;
//
//        try
//        {
//            int res = StoI(str1) + StoI(str2);
//            cout << str1 << " + " << str2 << " = " << res << endl;
//            break;
//        }
//        // char형 catch
//        catch(char c)
//        {
//            cout << "문자 " << c << "가 입력되었습니다" << endl;
//            cout << "재입력 진행합니다" << endl << endl;
//        }
//        catch(int expn)
//        {
//            if(expn == 0) cout << "0으로 시작되는 숫자는 입력불가" << endl;
//            else cout << "비정상적 입력이 이루어졌습니다" << endl;
//
//            cout << "재입력 진행" << endl;
//        }
//    }
//    cout << "end of program" << endl;
//}