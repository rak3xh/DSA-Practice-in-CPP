#include <bits/stdc++.h>
using namespace std;
string smallestNumber(int n, int k)
{
    // Write your code here
    if (n * 9 < k)
        return "-1";

    if (n != 1 && k == 0)
        return "-1";

    string ans(n, ' ');

    k--;

    for (int i = n - 1; i >= 0; i--)

    {

        int num = min(9, k);

        k -= num;

        if (i != 0)

            ans[i] = num + '0';

        else

            ans[i] = num + 1 + '0';
    }

    return ans;
}
