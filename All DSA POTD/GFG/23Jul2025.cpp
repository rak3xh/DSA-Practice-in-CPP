#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &arr)
    {
        // code here

        int ans = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int left = i + 1;
            int right = n - i;

            ans += left * right * arr[i];
        }

        return ans;
    }
};