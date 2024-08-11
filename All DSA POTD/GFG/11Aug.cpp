#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    void update(vector<long long> &seg, vector<long long> &v, int left, int right, int ind, long long val, int node)
    {
        if (left > right)
        {
            return;
        }

        if (ind < left || ind > right)
        {
            return;
        }

        if (left == right && ind == left)
        {
            seg[node] = val;
            return;
        }

        int mid = (left + right) / 2;
        update(seg, v, left, mid, ind, val, node * 2 + 1);
        update(seg, v, mid + 1, right, ind, val, node * 2 + 2);

        seg[node] = max(seg[node * 2 + 1], seg[node * 2 + 2]);

        return;
    }

    long long query(vector<long long> &seg, int left, int right, int node, int l, int r)
    {

        if (l >= left && r <= right)
        {
            // sum+=seg[node];
            return seg[node];
        }

        if (right < l || left > r)
        {
            return INT_MIN;
        }

        int mid = (l + r) / 2;

        long long ans = max(query(seg, left, right, node * 2 + 1, l, mid), query(seg, left, right, node * 2 + 2, mid + 1, r));

        return ans;
    }

    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        int count = 0;
        int ans = 0;
        vector<long long> Time(n, 0);
        vector<long long> seg(4 * n, 0);
        for (int i = 0; i < n; i++)
        {
            Time[i] = i + 1;
            update(seg, Time, 0, n - 1, i, i + 1, 0);
        }

        sort(arr, arr + n, cmp);

        for (int i = 0; i < n; i++)
        {
            int deadline = arr[i].dead;
            int prof = arr[i].profit;

            int tempans = query(seg, 0, deadline - 1, 0, 0, n - 1);

            if (tempans != 0)
            {
                ans += prof;
                count++;
                update(seg, Time, 0, n - 1, tempans - 1, 0, 0);
            }
        }

        return {count, ans};
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}