#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Enter the three sides of the triangle";
    cin >> a >> b >> c;
    if (((a + b) > c) && ((a + c) > b) && ((b + c) > a))
    {
        cout << "This is a Triangle";
    }

    else
    {
        cout << "This is not a triangle";
    }
    return 0;
}
