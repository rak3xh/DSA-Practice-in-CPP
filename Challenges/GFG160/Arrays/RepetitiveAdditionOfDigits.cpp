#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int singleDigit(int n)
    {
        // code here
        return --n % 9 + 1;
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
        int ans = ob.singleDigit(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}