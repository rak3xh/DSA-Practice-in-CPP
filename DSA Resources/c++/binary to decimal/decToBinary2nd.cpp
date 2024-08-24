#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0, i = 0;
    while (n != 0)
    {
        int digit = n & 1;
        n >>= 1;
        ans += (pow(10, i) * digit);
        i++;
    }
    cout << "The binary is:" << ans;
}