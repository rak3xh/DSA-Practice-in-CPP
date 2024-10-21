#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int countgroup(vector<int> &arr)
    {
        // Complete the function
        int mod = 1e9 + 7;
        int xor_ = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            xor_ ^= arr[i];
        if (xor_ != 0)
            return 0;
        return ((int)(pow(2, n - 1)) - 1) % mod;
    }
};

//{ Driver Code Starts.
int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}