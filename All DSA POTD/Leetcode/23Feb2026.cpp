#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        const int n = 1 << k;
        if (s.length() < n)
            return false;

        // used[i] := true if i is a substring of `s`
        vector<bool> used(n, false);

        int window = 0;

        // Build first k-1 bits
        for (int i = 0; i < k - 1; ++i)
        {
            window = (window << 1) + (s[i] - '0');
        }

        for (int i = k - 1; i < s.length(); ++i)
        {
            // Include s[i]
            window = (window << 1) + (s[i] - '0');

            // Keep only last k bits
            window &= (n - 1);

            used[window] = true;
        }

        // Replace ranges::all_of with std::all_of
        return all_of(used.begin(), used.end(), [](bool u)
                      { return u; });
    }
};