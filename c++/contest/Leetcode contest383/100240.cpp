#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTimeToInitialState(string word, int k)
    {
        vector<int> z = Z(word);
        int n = word.length();
        int ct = 0;

        for (int i = k; i < n; i += k)
        {
            ct++;
            if (z[i] == n - i)
            {
                return ct;
            }
        }
        return ct + 1;
    }

    vector<int> Z(string str)
    {
        int n = str.length();
        vector<int> z(n, 0);
        if (n == 0)
            return z;
        z[0] = n;
        int l = 0, r = 0;

        for (int i = 1; i < n; i++)
        {
            if (i > r)
            {
                l = r = i;
                while (r < n && str[r - l] == str[r])
                    r++;
                z[i] = r - l;
                r--;
            }
            else
            {
                if (z[i - l] < r - i + 1)
                {
                    z[i] = z[i - l];
                }
                else
                {
                    l = i;
                    while (r < n && str[r - l] == str[r])
                        r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }
};