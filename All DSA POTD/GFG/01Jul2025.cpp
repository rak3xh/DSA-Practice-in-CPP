#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int substrCount(string &s, int k)
    {
        // code here
        unordered_map<char, int> mp;
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            mp[s[i]]++;
        }
        if (mp.size() == k - 1)
        {
            ans++;
        }
        for (int i = k, j = 0; i < s.size(); i++, j++)
        {
            if (mp[s[j]] == 1)
            {
                mp.erase(s[j]);
            }
            else
            {
                mp[s[j]]--;
            }
            mp[s[i]]++;
            if (mp.size() == k - 1)
            {
                ans++;
            }
        }
        return ans;
    }
};