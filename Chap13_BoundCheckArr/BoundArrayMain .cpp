#include <iostream>
#include "ArrayTemplate.h"
#include "Point.h"
using namespace std;

int main()
{
    // int
    BoundCheckArray<int> iarr(5);
    for(int i = 0; i < 5; i++)
        iarr[i] = (i+1) * 11;
    for(int i = 0; i < 5; i++)
        cout << iarr[i] << endl;
    cout << endl;

    // Point 객체
    BoundCheckArray<Point> oarr(3);
    oarr[0] = Point(3, 4);
    oarr[1] = Point(2,2);
    oarr[2] = Point(5, 7);
    for(int i = 0; i < 3; i++)
        cout << oarr[i];
    cout << endl;

    // Point 객체의 주소값
    BoundCheckArray<Point*> parr(3);
    parr[0] = new Point(3, 4);
    parr[1] = new Point(2, 2);
    parr[2] = new Point(1, 2);
    for(int i = 0; i < 3; i++)
        cout << *(parr[i]);

    delete parr[0];
    delete parr[1];
    delete parr[2];

}