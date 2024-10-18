#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int getSingle(vector<int> &arr)
    {
        // code here
        auto first = arr.begin();
        auto last = arr.end();

        // calling the sort for the above defined range
        sort(first, last);

        for (int i = 1; i < arr.size(); i = i + 2)
        {
            if (arr[i] != arr[i - 1])
            {
                return arr[i - 1];
            }
        }

        return arr[arr.size() - 1];
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
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}