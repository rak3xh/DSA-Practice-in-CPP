#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int swapNibbles(int n)
    {
        // code here
        int temp1 = n;
        temp1 = temp1 << 4;
        temp1 &= 240;

        int temp2 = n;
        temp2 = temp2 >> 4;

        // cout<<temp1<<" "<<temp2<<endl;

        return (temp1 | temp2);
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
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}