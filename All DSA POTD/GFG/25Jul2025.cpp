#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxCircularSum(vector<int> &arr)
    {
        // code here
        int curr_max = arr[0], max_sum = arr[0];
        int curr_min = arr[0], min_sum = arr[0];
        int total = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            curr_max = max(arr[i], curr_max + arr[i]);
            max_sum = max(max_sum, curr_max);
            curr_min = min(arr[i], curr_min + arr[i]);
            min_sum = min(min_sum, curr_min);

            total += arr[i];
        }
        if (max_sum < 0)
            return max_sum;
        return max(max_sum, total - min_sum);
    }
};