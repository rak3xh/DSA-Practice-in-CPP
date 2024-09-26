#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int> &arr)
    {
        // Your code here
        int count = 0;
        int maxi = 0;

        for (int i = 0; i < arr.size() - 1; i++)
        {

            if (arr[i] < arr[i + 1])
            {
                count++;
            }
            else
            {
                maxi = max(maxi, count);
                count = 0;
            }
        }
        maxi = max(maxi, count);
        return maxi;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}