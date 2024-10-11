#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> rearrange(const vector<int> &arr)
    {
        // Code here
        vector<int> res(arr.begin(), arr.end());
        int n = arr.size();
        int i = 0;
        while (i < n)
        {
            if (res[i] == i)
            {
                i++;
            }
            else
            {
                if (res[i] != -1)
                {
                    swap(res[i], res[res[i]]);
                }
                else
                {
                    i++;
                }
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}