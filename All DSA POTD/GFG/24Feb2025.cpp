#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        // write code here
        int n = arr.size();

        vector<int> ans(n, 1);

        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && arr[i] >= st.top().first)
            {

                st.pop();
            }

            if (st.empty())
            {

                ans[i] = i + 1;
            }

            else
            {

                ans[i] = i - st.top().second;
            }

            st.push({arr[i], i});
        }
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}