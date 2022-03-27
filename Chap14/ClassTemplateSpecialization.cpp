
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Point
{
private:
    T xpos, ypos;

public:
    Point(T x = 0, T y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
};

// 클래스 템플릿 SimpleDataWrapper
template <typename T>
class SimpleDataWrapper
{
private:
    T mdata;
public:
    SimpleDataWrapper(T data) : mdata(data) {}
    void ShowDataInfo() { cout << "Data: " << mdata << endl; }
};

// 클래스 템플릿 SimpleDataWrapper를 char* 에 대하여 특수화
template<>
class SimpleDataWrapper<char*>
{
private:
    char *mdata;
public:
    SimpleDataWrapper(char *data)
    {
        mdata = new char[strlen(data)+1];
        strcpy(mdata, data);
    }
    void ShowDataInfo()
    {
        cout << "String: " << mdata << endl;
        cout << "Length: " << strlen(mdata) << endl;
    }
    ~SimpleDataWrapper() { delete []mdata; }
};

// 클래스 템플릿 SimpleDataWrapper를 텤플릿 클래스인 Point<int>형에 대하여 특수화
template<>
class SimpleDataWrapper<Point<int>>
{
private:
    Point<int> mdata;
public:
    SimpleDataWrapper(int x, int y) : mdata(x, y) {}
    void ShowDataInfo()
    {
        mdata.ShowPosition();
    }
};

int main()
{
    // int형은 특수화 없음.
    // 이 문장이 컴파일 될때  클래스 템플릿인 SimpleDataWrapper 을 기반으로
    // 템플릿 클래스인 SimpleDataWrapper<int>가 만들어짐.
    SimpleDataWrapper<int> iwrap(170);
    iwrap.ShowDataInfo(); cout << endl;

    // char* 형에 대하여 특수화 되있으므로 별도의 템플릿 클래스 생성하지 않고 정의되어 있는
    // 템플릿 클래스가 호출됨.
    SimpleDataWrapper<char*> swrap("HELLO WORLD!");
    swrap.ShowDataInfo(); cout << endl;

    SimpleDataWrapper<Point<int>> poswrap(3, 30);
    poswrap.ShowDataInfo();
}

template <typename T>
class Simple
{
public:
    T SimpleFunc(T num) {}
};

// Simple 템플릿 클래스를 int형에 대하여 특수화
template<>
class Simple<int>
{
public:
    int SimpleFunc(int num) {}
};