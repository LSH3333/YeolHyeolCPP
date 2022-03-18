#include <iostream>
using namespace std;

class Rectangle
{
private:
    int r, c;

public:
    Rectangle(int _r, int _c) : r(_r), c(_c) {}

    void ShowAreaInfo()
    {
        cout << "면적: " << r * c << endl;
    }
};

class Square : public Rectangle
{
public:
    Square(int _r) : Rectangle(_r, _r) {}
};

int main()
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
}