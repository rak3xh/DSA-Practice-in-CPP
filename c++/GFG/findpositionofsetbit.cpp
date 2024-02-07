#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPosition(int N)
    {
        // code here
        int noofone = 0;
        int noofzero = 0;
        int res = N;
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                noofone++;
            }
            if (N % 2 == 0)
            {
                noofzero++;
            }
            N = N >> 1;
        }
        if (noofone != 1)
        {
            return -1;
        }
        return noofzero + 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}