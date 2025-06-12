#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int k, int x)
    {
        // Code here
        vector<int> ans;
        int n = arr.size(), j = 0;
        int i = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (arr[i] == x)
        {
            j = i + 1;
            i--;
        }
        else
        {
            j = i;
            i = i - 1;
        }
        // cout<<i<<endl;
        while (k > 0)
        {
            int diff1 = i >= 0 ? abs(arr[i] - x) : INT_MAX;
            int diff2 = j < n ? abs(arr[j] - x) : INT_MAX;
            if (diff1 < diff2)
            {
                ans.push_back(arr[i]);
                i--;
            }
            else if (diff2 < diff1)
            {
                ans.push_back(arr[j]);
                j++;
            }
            else if (diff1 == diff2)
            {
                ans.push_back(arr[j]);
                j++;
                if (k - 1 > 0)
                {
                    ans.push_back(arr[i]);
                    i--;
                    k--;
                }
            }
            k--;
        }
        return ans;
    }
};