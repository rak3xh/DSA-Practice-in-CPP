#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumPushes(string word)
    {
        int ans = 0;
        vector<int> count(26, 0);

        for (const char c : word)
            ++count[c - 'a'];

        sort(count.begin(), count.end(), greater<int>());

        for (int i = 0; i < 26; ++i)
            ans += count[i] * (i / 8 + 1);

        return ans;
    }
};