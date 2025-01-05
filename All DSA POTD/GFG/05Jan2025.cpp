#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        // Your code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int i = 0, j = n - 1;
        int ans = 0, res = 0;
        while (i < j && i < n && j >= 0)
        {
            if ((arr[i] + arr[j]) >= target)
                j--;
            else
            {
                ans = (j - i + 1);
                res += (ans - 1);
                i++;
            }
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}