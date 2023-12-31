#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int a, int b, int c, int d)
{
    int max;
    if (a > b && a > c && a > d)
    {
        max = a;
    }
    else if (b > a && b > c && b > d)
    {
        max = b;
    }
    else if (c > a && c > b && c > d)
    {
        max = c;
    }
    else
    {
        max = d;
    }
    return max;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = max_of_four(a, b, c, d);
    cout << ans;

    return 0;
}