#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool solve(int i, int curSum, vector<int> &arr, int sum)
    {
        if (curSum > sum)
            return false;
        if (curSum == sum)
            return true;
        if (i == arr.size())
            return false;

        if (solve(i + 1, curSum + arr[i], arr, sum))
        {
            return true;
        }
        solve(i + 1, curSum, arr, sum);
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        return solve(0, 0, arr, sum);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
