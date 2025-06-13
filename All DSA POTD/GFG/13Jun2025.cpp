#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(int n, vector<int> &arr, long long mid, int k)
    {
        long long count = 0;
        for (int &num : arr)
        {
            count += (num + mid - 1) / mid; // ceil value ke liye
            if (count > k)
                return false;
        }
        return true;
    }
    int kokoEat(vector<int> &arr, int k)
    {
        // Code here
        int n = arr.size();
        long long l = 1; // min time 1 se start
        long long r = accumulate(arr.begin(), arr.end(), 0LL);
        long long minValue = r;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (isPossible(n, arr, mid, k))
            {
                minValue = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return (int)minValue;
    }
};