#include <bits/stdc++.h>
using namespace std;
vector<int> findSpans(vector<int> &price)
{
    // Write your code here.
    stack<pair<int, int>> st;
    int n = price.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int span = 1;
        while (!st.empty() && st.top().first <= price[i])
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price[i], span});
        ans.push_back(span);
    }
    return ans;
}
