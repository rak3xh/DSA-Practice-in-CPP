#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    int a = 0, b = 1;
    cout << "Enter the number of series you want: ";
    cin >> n;
    cout << endl
         << "The Fibonacci Series is: " << a << ", " << b << ", ";
    for (int i = 2; i < n; i++)
    {
        sum = a + b;
        cout << sum << ", ";
        a = b;
        b = sum;
    }
}