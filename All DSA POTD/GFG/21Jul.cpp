#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int findMaxProduct(vector<int> &arr)
    {
        // Write your code here
        long long int ans = 1;
        long long int maxNeg = INT_MIN;
        long long int cntZero = 0;
        long long int cntNeg = 0;
        long long int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                cntZero++;
                continue;
            }
            else if (arr[i] < 0)
            {
                cntNeg++;
                maxNeg = max(maxNeg, (long long int)arr[i]);
            }
            ans = ((ans % mod) * arr[i] % mod);
        }
        if (cntZero == arr.size() || (cntZero == arr.size() - 1 && cntNeg == 1))
            return 0;
        else if (cntNeg % 2 == 1)
            ans = (ans / maxNeg + mod) % mod;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}