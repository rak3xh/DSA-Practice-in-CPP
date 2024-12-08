#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        // Code here
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int cs = arr[0][0];
        int ce = arr[0][1];
        int ps = cs, pe = ce;
        for (int i = 1; i < arr.size(); i++)
        {
            cs = arr[i][0];
            ce = arr[i][1];
            if (cs <= pe && ce > pe)
            {
                pe = ce;
            }
            else if (cs > pe)
            {
                ans.push_back({ps, pe});
                ps = cs;
                pe = ce;
            }
        }
        ans.push_back({ps, pe});
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}