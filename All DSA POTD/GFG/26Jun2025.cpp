#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minValue(string &s, int k)
    {
        // code here
        priority_queue<int> q;
        int arr[26] = {};
        for (int i = 0; i < s.length(); i++)
        {
            arr[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] > 0)
            {
                q.push(arr[i]);
            }
        }

        while (k--)
        {
            int top = q.top();
            q.pop();
            if (top - 1 > 0)
            {
                q.push(top - 1);
            }
        }

        long long int ans = 0;
        while (!q.empty())
        {
            int top = q.top();
            ans += (1ll * top * top);
            q.pop();
        }

        return ans;
    }
};