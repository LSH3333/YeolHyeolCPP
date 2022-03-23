#include <iostream>
#include <cstdio>
using namespace std;

class String
{
private:
    char * str;

public:
    // 생성자
    String(const char *_str)
    {
        str = new char[strlen(_str) + 1];
        strcpy(str, _str);
    }
    // 복사 생성자
    String(const String& ref)
    {
        str = new char[strlen(ref.str)];
        strcpy(str, ref.str);
    }
    // = 연산자 오버로딩
    String& operator= (const String& ref)
    {
        if(str != NULL) delete []str;
        str = new char[strlen(ref.str)];
        strcpy(str, ref.str);
        return *this;
    }

    // + 연산자 오버로딩
    String operator+ (const String& ref)
    {
        char * tmp = new char[strlen(str) + strlen(ref.str) - 1];
        strcpy(tmp, str);
        strcat(tmp, ref.str);
        String tmpStr(tmp);
        delete []tmp;
        return tmpStr;
    }

    // += 연산자 오버로딩
    String& operator+= (const String& ref)
    {
        char * tmp = new char[strlen(str) + strlen(ref.str) - 1];
        strcpy(tmp, str);
        strcat(tmp, ref.str);
        if(str != NULL) delete []str;
        str = tmp;
        return *this;
    }

    // == 연산자 오버로딩
    bool operator== (const String& ref)
    {
        if(strlen(str) != strlen(ref.str)) return false;
        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] != ref.str[i]) return false;
        }
        return true;
    }

    ~String()
    {
        if(str != NULL)
            delete []str;

    }

    friend ostream& operator<< (ostream& os, const String& ref);
    friend istream& operator>> (istream& is, String& ref);
};

// << 연산자 오버로딩
ostream& operator<< (ostream& os, const String& ref)
{
    os << ref.str;
    return os;
}

// >> 연산자 오버로딩
istream& operator>> (istream& is, String& ref)
{
    is >> ref.str;
    return is;
}

int main()
{
    String str1 = "I like ";
    String str2 = "string Class";
    String str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if(str1 == str3)
        cout << "same string" << endl;
    else
        cout << "diff string" << endl;

    string str4;
    cout << "Enter String: ";
    cin >> str4;
    cout << "Your String: " << str4 << endl;

    return 0;
}