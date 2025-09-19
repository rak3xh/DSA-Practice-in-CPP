#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minParentheses(string &s)
    {
        // code here
        int openParam = 0;
        int closeParam = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                openParam++;
            }
            else if (openParam > 0)
            {
                openParam--;
            }
            else
            {
                closeParam++;
            }
        }
        return openParam + closeParam;
    }
};