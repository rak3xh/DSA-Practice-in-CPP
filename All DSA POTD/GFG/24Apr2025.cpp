#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int getSingle(vector<int> &arr)
    {
        // code here
        vector<int> bits(32, 0);
        auto func = [&](int n) -> void
        {
            for (int i = 0; i < 32; i++)
            {
                int mask = (1 << i);
                if (mask & n)
                    bits[i]++;
            }
        };

        for (auto &num : arr)
        {
            func(num);
        }
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bits[i] % 3)
                res |= (1 << i);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
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
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
