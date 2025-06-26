#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[11][16];

    int solve(int digit, int n, unordered_map<int, vector<int>> &mp)
    {

        if (n == 1)
            return 1;

        if (dp[digit][n] != -1)
            return dp[digit][n];
        int ans = 0;

        for (auto it : mp[digit])
            ans += solve(it, n - 1, mp);

        return dp[digit][n] = ans;
    }
    int getCount(int n)
    {
        // code here
        unordered_map<int, vector<int>> mp;
        mp[0] = {0, 8};
        mp[1] = {1, 2, 4};
        mp[2] = {2, 1, 3, 5};
        mp[3] = {3, 2, 6};
        mp[4] = {4, 1, 5, 7};
        mp[5] = {5, 2, 4, 6, 8};
        mp[6] = {6, 3, 5, 9};
        mp[7] = {7, 4, 8};
        mp[8] = {8, 5, 7, 9, 0};
        mp[9] = {9, 6, 8};

        if (n == 1)
            return 10;
        int total = 0;

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i <= 9; i++)
        {

            total += solve(i, n, mp);
        }

        return total;
    }
};