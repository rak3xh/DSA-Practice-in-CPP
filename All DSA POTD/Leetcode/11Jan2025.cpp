#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        bitset<26> odd;

        for (char c : s)
        {
            odd.flip(c - 'a');
        }

        return odd.count() <= k && k <= s.size();
    }
};