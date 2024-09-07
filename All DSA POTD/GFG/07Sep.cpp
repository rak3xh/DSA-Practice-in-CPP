
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long findNth(long long n)
    {
        // code here.
        int i = 1;
        long long l = n % 9;
        n = n / 9;
        while (n > 0)
        {
            l = ((n % 9) * pow(10, i)) + l;
            n = n / 9;
            i++;
        }
        return l;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}
