#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    bool canAttend(vector<vector<int>> &arr)
    {
        // Your Code Here
        int n = arr.size();
        vector<int> line(2000001, 0);
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int start = arr[i][0];
            int end = arr[i][1];
            line[start] += 1;
            line[end] -= 1;
            maxi = max(maxi, end);
        }
        int cnt = 0;
        for (int i = 0; i <= maxi; i++)
        {
            cnt += line[i];
            if (cnt > 1)
            {
                return false;
            }
        }
        return true;
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
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}