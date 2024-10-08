#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int pairsum(vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size() - 1;
        int sum = arr[n] + arr[n - 1];
        return sum;
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
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}