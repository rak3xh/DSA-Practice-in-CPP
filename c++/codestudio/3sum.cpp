#include <bits/stdc++.h>
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
int main()
{
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }
    int k;
    cin >> k;
    vector<vector<int>> answer = findTriplets(a, n, k);
    for (const auto &row : answer)
    {
        for (int element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}