#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodedString(string &s)
    {
        // code here
        stack<string> strStack;
        stack<int> numStack;
        string res = "";
        int num = 0;

        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (isalpha(c))
            {
                res += c;
            }
            else if (c == '[')
            {
                strStack.push(res);
                numStack.push(num);
                res = "";
                num = 0;
            }
            else if (c == ']')
            {
                string temp = res;
                res = strStack.top();
                strStack.pop();
                int count = numStack.top();
                numStack.pop();
                while (count--)
                {
                    res += temp;
                }
            }
        }

        return res;
    }
};