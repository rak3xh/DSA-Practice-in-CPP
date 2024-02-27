#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int DivisibleByEight(string s)
    {
        // code here
        int n = s.length();

        if (s == "8" || s == "16")
            return 1;
        else if (n <= 2)
            return -1;

        int a = stoi(s.substr(n - 3));
        return !(a % 8) ? 1 : -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.DivisibleByEight(S) << "\n";
    }
}