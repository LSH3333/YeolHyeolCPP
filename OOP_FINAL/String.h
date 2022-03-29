#ifndef OOP_FINAL_STRING_H
#define OOP_FINAL_STRING_H

#include "BankingCommon.h"

class String
{
private:
    char *str;
public:
    String(); // 생성자
    String(const char *_str); // 생성자
    String(const String &ref); // 복사 생성자
    String& operator= (const String &ref); // 대입 연산자 오버로딩
    String operator+ (const String &ref); // +연산자
    String& operator+= (const String &ref); // += 연산자
    bool operator== (const String &ref); // == 연산자
    ~String(); // 소멸자

    // 전역으로 선언한 연산자 오버로딩
    friend ostream& operator<< (ostream &os, const String &ref);
    friend istream& operator>> (istream &is, String &ref);
};

#endif //OOP_FINAL_STRING_H
