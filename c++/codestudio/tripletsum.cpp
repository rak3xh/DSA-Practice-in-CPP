#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    vector<vector<int>> ans;
    set<vector<int>> temp;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] == K)
            {
                temp.insert({arr[i], arr[j], arr[k]});
            }
            if (arr[i] + arr[j] + arr[k] > K)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    for (auto i : temp)
    {
        ans.push_back(i);
    }

    return ans;
}