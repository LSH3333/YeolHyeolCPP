#include <iostream>
namespace mystd
{
    using namespace std;

    class ostream
    {
    public:
        ostream& operator<< (char *str) // 문자열
        {
            printf("%s", str);
            return *this;
        }
        ostream& operator<< (char str) // 문자
        {
            printf("%c", str);
            return *this;
        }
        ostream& operator<< (int num) // 정수
        {
            printf("%d", num);
            return *this;
        }
        ostream& operator<< (double e) // 실수형
        {
            printf("%g", e);
            return *this;
        }
        ostream& operator<< (ostream& (*fp)(ostream &ostm))
        {
            return fp(*this);
        }
    };

    ostream& endl(ostream &ostm)
    {
        ostm << '\n';
        fflush(stdout); // 버퍼 비움
        return ostm;
    }

    ostream cout; // cout은 객체의 이름이다
}

int main()
{
    using mystd::cout;
    using mystd::endl;

    cout << "Simple String";
    cout << endl; // cout.operator(endl)
    cout << 3.14 << endl << 123 << endl;

}
