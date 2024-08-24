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
        int num = n % 10;
        if (num == 1)

            ans += pow(2, i);
        n = n / 10;
        i++;
    }
    cout << "The Decimal number is: " << ans;
}