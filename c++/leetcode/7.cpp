#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;
int reverse(int x)
{
    long ans = 0;
    while (x != 0)
    {
        int digit = x % 10;
        x = x / 10;
        ans = (ans * 10) + digit;
    }
    if (ans > INT_MAX || ans < INT_MIN)

        return 0;

    return int(ans);
}
int main()
{
    int x;
    cin >> x;
    int ans = reverse(x);
    cout << "answer  " << ans;
}