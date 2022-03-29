#include "String.h"

String::String()
{
    str = NULL;
}
// 생성자, 문자열 동적할당
String::String(const char *_str)
{
    str = new char[strlen(_str)+1];
    strcpy(str, _str);
}
// 복사 생성자
String::String(const String &ref)
{
    str = new char[strlen(ref.str)];
    strcpy(str, ref.str);
}
// 대입 연산자 오버로딩
String& String::operator= (const String &ref)
{
    // 기존에 가르키고 있던 문자열있다면 지움
    if(str != NULL) delete []str;
    str = new char[strlen(ref.str)];
    strcpy(str, ref.str);
    // 현재 객체의 레퍼런스 리턴
    return *this;
}
// + 연산자 오버로딩
String String::operator+ (const String &ref)
{
    char *tmp = new char[strlen(str) + strlen(ref.str)-1];
    strcpy(tmp, str);
    strcat(tmp, ref.str);
    String tmpStr(tmp);
    delete []tmp;
    return tmpStr;
}
// += 연산자 오버로딩
String& String::operator+=(const String &ref)
{
    char *tmp = new char[strlen(str) + strlen(ref.str)-1];
    strcpy(tmp, str);
    strcat(tmp, ref.str);
    if(str != NULL) delete []str;
    str = tmp;
    return *this;
}
// == 연산자 오버로딩
bool String::operator== (const String &ref)
{
    if(strlen(str) != strlen(ref.str)) return false;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] != ref.str[i]) return false;
    }
    return true;
}
// 소멸자
String::~String()
{
    if(str != NULL) delete []str;
}

// 전역
// << 연산자 오버로딩
ostream& operator<< (ostream &os, const String &ref)
{
    os << ref.str;
    return os;
}

// >> 연산자 오버로딩
istream& operator>> (istream& is, String &ref)
{
    char str[100];
    is >> str;
    ref = String(str);
    return is;
}