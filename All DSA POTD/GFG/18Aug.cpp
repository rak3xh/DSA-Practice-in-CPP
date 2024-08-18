#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }
        int sum = 0;
        int sum2 = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            sum2 = sum2 + arr[i];
            sum = sum - arr[i];
            if (sum == sum2)
            {
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp)
        {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}