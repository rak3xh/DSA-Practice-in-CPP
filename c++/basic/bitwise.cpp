#include <iostream>
using namespace std;
int main()
{
    int a = 5, b = 6;
    int c = a & b;
    int d = a | b;
    int e = ~a;
    int f = a ^ b;
    cout << c << endl
         << d << endl
         << e << endl
         << f << endl
         << (a << 2);
}