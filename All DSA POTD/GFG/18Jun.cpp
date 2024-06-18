#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int rectanglesInCircle(int r)
    {
        // code here
        int ans = 0;
        for (int i = 1; i < 2 * r; i++)
        {
            int t = sqrt(4 * r * r - i * i);
            ans += t;
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
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
