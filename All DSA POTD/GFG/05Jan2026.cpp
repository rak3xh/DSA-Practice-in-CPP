#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < k - 1; i++)
        {
            sum += arr[i];
        }

        int start = 0;
        int end = k - 1;

        while (end < n)
        {
            sum += arr[end];
            ans = max(ans, sum);

            sum -= arr[start];
            start++;

            end++;
        }

        return ans;
    }
};