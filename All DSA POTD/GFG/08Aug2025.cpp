#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getLPSLength(string &s)
    {
        // code here
        char ch = s[0];
        int n = s.length();
        vector<int> idx;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ch)
                idx.push_back(i);
        }

        for (int i = 0; i < idx.size(); i++)
        {
            int j = 0, t = idx[i];
            int ok = true;
            while (t < n)
            {
                if (s[j] == s[t])
                {
                    j += 1;
                    t += 1;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return n - idx[i];
        }
        return 0;
    }
};