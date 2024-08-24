#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    bool PossibleSolution(vector<int> &stalls, int k, int mid)
    {
        int n = stalls.size();
        int CowsCount = 1;
        int LastPosition = stalls[0];
        for (int i = 0; i < n; i++)
        {
            if ((stalls[i] - LastPosition) >= mid)
            {
                CowsCount++;
                if (CowsCount == k)
                {
                    return true;
                }
                LastPosition = stalls[i];
            }
        }
        return false;
    }

public:
    int solve(int n, int k, vector<int> &stalls)
    {

        sort(stalls.begin(), stalls.end());
        int s = 0;
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, stalls[i]);
        }
        int e = maxi;
        int mid = s + (e - s) / 2;
        int ans = 0;
        while (s <= e)
        {
            if (PossibleSolution(stalls, k, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}