#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr)
    {
        // Code Here
        int first = 0, second = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > first)
            {
                second = first;
                first = arr[i];
            }
            else if (second < arr[i] && arr[i] != first)
            {
                second = arr[i];
            }
        }
        return second;
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
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}
