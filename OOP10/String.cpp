#include "String.h"

String::String()
{
    str = NULL;
}
// 생성자
String::String(const char *_str)
{
    str = new char[strlen(_str) + 1];
    strcpy(str, _str);
}
// 복사 생성자
String::String(const String& ref)
{
    str = new char[strlen(ref.str)];
    strcpy(str, ref.str);
}
// = 연산자 오버로딩
String& String::operator= (const String& ref)
{
    if(str != NULL) delete []str;
    str = new char[strlen(ref.str)];
    strcpy(str, ref.str);
    return *this;
}

// + 연산자 오버로딩
String String::operator+ (const String& ref)
{
    char * tmp = new char[strlen(str) + strlen(ref.str) - 1];
    strcpy(tmp, str);
    strcat(tmp, ref.str);
    String tmpStr(tmp);
    delete []tmp;
    return tmpStr;
}

// += 연산자 오버로딩
String& String::operator+= (const String& ref)
{
    char * tmp = new char[strlen(str) + strlen(ref.str) - 1];
    strcpy(tmp, str);
    strcat(tmp, ref.str);
    if(str != NULL) delete []str;
    str = tmp;
    return *this;
}

// == 연산자 오버로딩
bool String::operator== (const String& ref)
{
    if(strlen(str) != strlen(ref.str)) return false;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] != ref.str[i]) return false;
    }
    return true;
}

String::~String()
{
    if(str != NULL)
        delete []str;

}

// 전역
// << 연산자 오버로딩
ostream& operator<< (ostream& os, const String& ref)
{
    os << ref.str;
    return os;
}

// >> 연산자 오버로딩
istream& operator>> (istream& is, String& ref)
{
    char str[100];
    is >> str;
    ref = String(str);
    return is;
}