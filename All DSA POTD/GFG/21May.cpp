#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        // code here
        int ind = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        vector<int> ans;
        int i = 0;
        if (arr[ind - 1] == x)
        {
            i = ind - 2;
        }
        else
        {
            i = ind - 1;
        }
        int j = ind;
        int count = 0;
        while (count < k)
        {
            if (i < 0)
            {
                ans.push_back(arr[j]);
                ++j;
                ++count;
            }
            else if (j >= n)
            {
                ans.push_back(arr[i]);
                --i;
                ++count;
            }
            else if (abs(x - arr[j]) <= abs(x - arr[i]))
            {
                ans.push_back(arr[j]);
                ++count;
                ++j;
            }
            else
            {
                ans.push_back(arr[i]);
                ++count;
                --i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
