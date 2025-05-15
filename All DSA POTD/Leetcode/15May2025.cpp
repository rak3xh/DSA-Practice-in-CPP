#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> ans;
        int n = groups.size();
        int groupId = -1;

        for (int i = 0; i < n; ++i)
            if (groups[i] != groupId)
            {
                groupId = groups[i];
                ans.push_back(words[i]);
            }

        return ans;
    }
};