#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        if (n == 0)
        {
            return 0;
        }
        unsigned int i = 1;
        while (n != 0)
        {
            if ((n & 1) == 1)
            {
                return i;
            }
            n >>= 1;
            i++;
        }
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
    return 0;
}
