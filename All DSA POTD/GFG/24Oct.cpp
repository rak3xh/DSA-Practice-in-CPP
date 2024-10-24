#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr)
    {
        // Complete the function
        vector<int> ans;
        int zeroc = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && arr[i] == arr[i + 1])
            {
                ans.push_back(2 * arr[i]);
                zeroc++;
                i++;
            }
            else if (arr[i] != 0)
            {
                ans.push_back(arr[i]);
            }
            else
                zeroc++;
        }

        for (int i = 0; i < zeroc; i++)
            ans.push_back(0);

        return ans;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
