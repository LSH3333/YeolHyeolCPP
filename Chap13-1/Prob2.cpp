#include <iostream>
using namespace std;

template <typename T>
T SumArray(T arr[], int len)
{
    T sum = 0;
    for(int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr[] = {1,2,3};
    cout << SumArray(arr,  3) << endl;

    double arr_d[] = {1.2, 3.2, 2.2};
    cout << SumArray(arr_d, 3) << endl;
}

