#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string t(s.rbegin(), s.rend()); // Reverse the string 's'

        int n = s.length();
        int i = 0;

        // Find the largest palindrome starting from the beginning of 's'
        for (int j = 0; j < n; ++j)
        {
            if (s.substr(0, n - j) == t.substr(j))
            {
                return t.substr(0, j) + s;
            }
        }

        return t + s; // In case no match, return the full reverse + original string
    }
};