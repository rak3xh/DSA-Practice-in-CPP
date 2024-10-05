#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long findSmallest(vector<int> &arr)
    {
        // Your code goes here.
        sort(arr.begin(), arr.end());

        // Initialize the result to the smallest positive integer
        int res = 1;

        // Traverse the array
        for (int i = 0; i < arr.size(); i++)
        {
            // If arr[i] is greater than res, we cannot form res
            if (arr[i] > res)
            {
                break;
            }
            // Otherwise, add arr[i] to res
            res += arr[i];
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num)
        {
            arr.push_back(num);
        }

        Solution ob;
        auto ans = ob.findSmallest(arr);
        cout << ans << "\n";
    }
    return 0;
}