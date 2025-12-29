#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<string, vector<char>> mp;
    unordered_set<string> bad; // rows that cannot form a pyramid
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        for (auto &a : allowed)
        {
            mp[a.substr(0, 2)].push_back(a[2]);
        }
        return dfs(bottom);
    }

private:
    bool dfs(const string &row)
    {
        if (row.size() == 1)
            return true;

        if (bad.count(row))
            return false;

        string nextRow;
        bool ok = buildNext(row, 0, nextRow);
        if (!ok)
            bad.insert(row);

        return ok;
    }

    bool buildNext(const string &row, int i, string &nextRow)
    {
        if (i + 1 == row.size())
            return dfs(nextRow);

        string key = row.substr(i, 2);
        if (!mp.count(key))
            return false;

        for (char c : mp[key])
        {
            nextRow.push_back(c);
            if (buildNext(row, i + 1, nextRow))
                return true;
            nextRow.pop_back();
        }

        return false;
    }
};