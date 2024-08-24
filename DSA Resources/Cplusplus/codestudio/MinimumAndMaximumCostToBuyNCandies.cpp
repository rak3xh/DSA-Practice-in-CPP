#include <bits/stdc++.h>
using namespace std;
long long minimumCost(vector<int> &cost, int n, int k)

{

    sort(cost.begin(), cost.end());

    int i = 0, j = n - 1;

    long long ans = 0;

    while (i <= j)

    {

        ans = ans + cost[i];

        j = j - k;

        i++;
    }

    return ans;
}

// Function to calculate maximum cost.

long long maximumCost(vector<int> &cost, int n, int k)

{

    sort(cost.begin(), cost.end(), greater<int>());

    int i = 0, j = n - 1;

    long long ans = 0;

    while (i <= j)

    {

        ans = ans + cost[i];

        j = j - k;

        i++;
    }

    return ans;
}