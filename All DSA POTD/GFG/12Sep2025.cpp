#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        if (n == 1)
            return 0;

        sort(arr.begin(), arr.end());

        int ans = arr[n - 1] - arr[0]; // initial difference

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 0; i < n - 1; i++)
        {
            int minH = min(smallest, arr[i + 1] - k);
            int maxH = max(largest, arr[i] + k);

            if (minH < 0)
                continue; // skip if height becomes negative

            ans = min(ans, maxH - minH);
        }

        return ans;
    }
};