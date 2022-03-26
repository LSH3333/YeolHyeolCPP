
#ifndef __STRING_H__
#define __STRING_H__

#include "BankingCommon.h"

class String
{
private:
    char *str;
public:
    String();
    String(const char *_str);
    String(const String &ref);
    String& operator= (const String& ref);
    String operator+ (const String& ref);
    String& operator+= (const String& ref);
    bool operator== (const String& ref);
    ~String();

    friend ostream& operator<< (ostream& os, const String& ref);
    friend istream& operator>> (istream& is, String& ref);
};

#endif // __STRING_H__
