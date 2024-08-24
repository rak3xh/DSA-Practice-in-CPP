#include <bits/stdc++.h>
using namespace std;
int baseConversion(string &num, int base)
{
    int power = 1, ans = 0;
    reverse(num.begin(), num.end());
    for (auto it : num)
    {
        int num;
        if (it >= 'A' && it <= 'F')
            num = it - 'A' + 10;
        else
            num = it - '0';
        if (num >= base)
            return -1;
        ans += power * num;
        power *= base;
    }
    return ans;
}