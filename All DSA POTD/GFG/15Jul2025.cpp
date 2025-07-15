#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool divby13(string &s)
    {
        // code here
        int n = s.length();
        if (n < 2)
            return false;
        int num = s[0] - '0';
        for (int i = 1; i < n; i++)
        {
            num *= 10;
            num += (s[i] - '0');
            num %= 13;
        }
        if (num == 0)
            return true;
        return false;
    }
};