#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // Your code here
        priority_queue<pair<int, vector<int>>> p;
        for (auto &i : points)
        {
            int x = i[0], y = i[1];
            int dis = x * x + y * y;
            p.push({dis, i});
            if (p.size() > k)
                p.pop();
        }
        vector<vector<int>> v;
        for (int i = 0; i < k; i++)
        {
            v.push_back(p.top().second);
            p.pop();
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int> &point : ans)
        {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}
