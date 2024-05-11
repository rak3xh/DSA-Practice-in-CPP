
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<long long> ans;
    vector<long long> jugglerSequence(long long n)
    {
        // code here
        if (ans.empty())
        {
            ans.push_back(n);
        }
        if (n == 1)
        {
            return ans;
        }
        else
        {
            if (n % 2 == 0)
            {
                n = sqrt(n);
                ans.push_back(n);
            }
            else
            {
                n = sqrt(n) * sqrt(n) * sqrt(n);
                ans.push_back(n);
            }
        }
        return jugglerSequence(n);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}