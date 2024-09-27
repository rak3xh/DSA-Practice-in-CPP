#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr)
    {
        // your code here
        int n = arr.size();
        if (k > n)
            return {};
        priority_queue<pair<int, int>> pq;
        int sum = 0;
        int st = 1;
        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i], i});
        }
        ans.push_back(pq.top().first);

        for (int i = k; i < n; i++)
        {
            pq.push({arr[i], i});
            while (!pq.empty() && pq.top().second < st)
                pq.pop();
            ans.push_back(pq.top().first);
            st++;
        }
        return ans;
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

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
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
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
