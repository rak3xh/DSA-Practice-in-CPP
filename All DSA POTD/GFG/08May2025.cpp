
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution
{
public:
    int findMissing(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int temp = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (temp == INT_MAX)
                temp = abs(arr[i] - arr[i - 1]);
            else
            {
                if (temp != abs(arr[i] - arr[i - 1]))
                {
                    if (temp < arr[i] - arr[i - 1])
                    {

                        if (arr[0] < arr[1])
                            return arr[i - 1] + temp;
                        else
                            return arr[i - 1] - temp;
                    }
                    else
                    {
                        if (arr[0] < arr[1])
                            return arr[i - 2] + (arr[i] - arr[i - 1]);
                        else
                            return arr[i - 2] - abs(arr[i] - arr[i - 1]);
                    }
                }
            }
        }
        if (arr[0] < arr[1])
            return arr[n - 1] + temp;
        else
            return arr[n - 1] - temp;
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}
