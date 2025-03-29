#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        // code here
        vector<pair<int, int>> vp;
        int n = deadline.size(), jobs = 0, maxProfit = 0;
        for (int i = 0; i < n; i++)
            vp.push_back({deadline[i], profit[i]});
        sort(vp.begin(), vp.end());
        priority_queue<int> pq;
        int index = n - 1;
        for (int i = vp[n - 1].first; i >= 1; i--)
        {
            while (index >= 0 && i == vp[index].first)
            {
                pq.push(vp[index].second);
                index--;
            }
            if (!pq.empty())
            {
                jobs++;
                maxProfit += pq.top();
                pq.pop();
            }
        }
        return {jobs, maxProfit};
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
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}
