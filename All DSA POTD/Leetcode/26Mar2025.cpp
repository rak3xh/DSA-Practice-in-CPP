// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> arr;
        for (const vector<int> &row : grid)
            arr.insert(arr.end(), row.begin(), row.end());

        for (int a : arr)
        {
            if ((a - arr[0]) % x != 0)
                return -1;
        }

        int ans = 0;

        nth_element(arr.begin(), arr.begin() + arr.size() / 2, arr.end());
        int median = arr[arr.size() / 2];

        for (int a : arr)
            ans += abs(a - median) / x;

        return ans;
    }
};
// C++ 20 Solution
/*
class Solution
{
    public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> arr;
        for (const vector<int> &row : grid)
        arr.insert(arr.end(), row.begin(), row.end());
        if (ranges::any_of(arr, [&](int a)
        { return (a - arr[0]) % x; }))
        return -1;
        
        int ans = 0;
        
        nth_element(arr.begin(), arr.begin() + arr.size() / 2, arr.end());
        
        for (const int a : arr)
        ans += abs(a - arr[arr.size() / 2]) / x;
        
        return ans;
    }
};
*/