#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int ans = 0;
        int p = 1;
        while (p <= n)
        {
            int grp = (n / (p * 2));

            ans += p * grp;

            int rem = n - (grp * p * 2);

            if (rem >= p)
                ans += rem - p + 1;

            p *= 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}
