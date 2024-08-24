#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool PossibleSolution(vector<long long int> &trees, long long int m, long long int mid)
{
    long long int Sum = 0;
    for (long long int i = 0; i < trees.size(); i++)
    {
        if (trees[i] > mid)
        {
            Sum += trees[i] - mid;
        }
    }
    if (Sum >= m)
    {
        return true;
    }
    return false;
}
long long int MaximumHeight(vector<long long int> &trees, long long int m)
{
    long long int start = 0;
    long long int end = trees[trees.size() - 1];
    long long int mid = start + (end - start) / 2;
    long long int ans = 0;
    while (start <= end)
    {
        if (PossibleSolution(trees, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - mid) / 2;
    }
    return ans;
}
int main()
{
    long long int N, M;
    cin >> N >> M;
    vector<long long int> trees;
    for (long long int i = 0; i < N; i++)
    {
        long long int input;
        cin >> input;
        trees.push_back(input);
    }
    sort(trees.begin(), trees.end());
    long long int ans = MaximumHeight(trees, M);
    cout << ans;
    return 0;
}