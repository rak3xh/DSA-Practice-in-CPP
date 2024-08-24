#include <bits/stdc++.h>

using namespace std;

void breaks(string &s, int idx, vector<string> &dic, set<string> &ans, string ss)
{

    if (idx == s.size())
    {

        ans.insert(ss);

        return;
    }

    for (int i = idx; i < s.size(); i++)
    {

        string target = s.substr(idx, i - idx + 1);

        if (find(dic.begin(), dic.end(), target) != dic.end())
        {

            breaks(s, i + 1, dic, ans, ss + target + " ");
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dic)
{

    set<string> ansSet;

    string ss = "";

    breaks(s, 0, dic, ansSet, ss);

    vector<string> ans(ansSet.begin(), ansSet.end());

    return ans;
}