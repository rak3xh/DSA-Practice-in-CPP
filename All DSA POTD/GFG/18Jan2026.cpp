#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextFreqGreater(vector<int> &arr)
    {
        // code here
        int n = arr.size();

        stack<int> st;
        map<int, int> mp;
        vector<int> ans(n, -1);

        for (auto &x : arr)
            mp[x]++;

        st.push(arr.back());

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && mp[st.top()] <= mp[arr[i]])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }

            st.push(arr[i]);
        }

        return ans;
    }
};
