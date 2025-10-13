#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans;

        for (int i = 0; i < (int)words.size();)
        {
            int j = i + 1;
            while (j < (int)words.size() && isAnagram(words[i], words[j]))
                ++j;
            ans.push_back(words[i]);
            i = j;
        }

        return ans;
    }

private:
    bool isAnagram(const string &a, const string &b)
    {
        if (a.length() != b.length())
            return false;

        vector<int> count(26, 0);

        for (char c : a)
            ++count[c - 'a'];

        for (char c : b)
            --count[c - 'a'];

        for (int c : count)
            if (c != 0)
                return false;

        return true;
    }
};