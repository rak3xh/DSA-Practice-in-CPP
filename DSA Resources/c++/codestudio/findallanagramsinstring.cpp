#include <bits/stdc++.h>
using namespace std;
vector<int> findAnagramsIndices(string str, string ptr, int n, int m)
{
    vector<int> ans;

    sort(ptr.begin(), ptr.end());

    for (int i = 0; i < n; i++)
    {
        string s = str.substr(i, m);
        sort(s.begin(), s.end());

        if (ptr.compare(s) == 0)
            ans.push_back(i);
    }
    return ans;
}