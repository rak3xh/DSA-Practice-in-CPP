#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.size();
        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (int(num[i]) % 2 != 0)
            {
                ans = ans + num;
                break;
            }
            num.erase(num.begin() + i);
        }
        return ans;
    }
};