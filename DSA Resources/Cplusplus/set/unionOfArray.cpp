#include <bits/stdc++.h>
using namespace std;
void findUnion(vector<int> &a, vector<int> &b)
{
    set<int> ans;
    for (auto it : a)
    {
        ans.insert(it);
    }
    for (auto it : b)
    {
        ans.insert(it);
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
int main()
{
    vector<int> a;
    vector<int> b;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    findUnion(a, b);
    return 0;
}