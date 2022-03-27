#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T Max(T a, T b)
{
    return a > b ? a : b;
}

// 함수 템플릿의 특수화
// char* 형에 대해 특수화
// 문자열의 길이에 대한 비교를 하고있다
template <>
char* Max<char*>(char *a, char *b)
{
    return strlen(a) > strlen(b) ? a : b;
}

// 사전순
template<>
const char* Max<const char*>(const char *a, const char *b)
{
    return strcmp(a, b) > 0 ? a : b;
}