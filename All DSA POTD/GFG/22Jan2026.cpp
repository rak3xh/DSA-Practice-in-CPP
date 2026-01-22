#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarrayRanges(vector<int> &v)
    {
        // code here
        int n = v.size();
        long long ans = 0;
        stack<int> st;
        for (int i = 0; i <= n; i++)
        {
            int x;
            if (i == n)
                x = INT_MIN;
            else
                x = v[i];
            while (st.size() && v[st.top()] >= x)
            {
                int idx = st.top(), l = -1;
                st.pop();
                if (st.size())
                    l = st.top();
                ans -= (i - idx) * (idx - l) * v[idx];
            }

            if (i < n)
                st.push(i);
        }
        for (int i = 0; i <= n; i++)
        {
            int x;
            if (i == n)
                x = INT_MAX;
            else
                x = v[i];
            while (st.size() && v[st.top()] <= x)
            {
                int idx = st.top(), l = -1;
                st.pop();
                if (st.size())
                    l = st.top();
                ans += (i - idx) * (idx - l) * v[idx];
            }

            if (i < n)
                st.push(i);
        }
        return int(ans);
    }
};