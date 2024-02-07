#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int isBitSet(int N)
    {
        // code here
        int flag = 0;
        if (N == 0)
        {
            return 0;
        }
        while (N)
        {
            if ((N & 1) == 1)
            {
                N >>= 1;
            }
            else
            {
                flag = 1;
                break;
            }
        }

        return (flag ? 0 : 1);
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
        cout << ob.isBitSet(N) << endl;
    }
    return 0;
}