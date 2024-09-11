#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long> &arr)
    {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long ans = 0;
        for (auto x : arr)
        {
            pq.push(x);
        }
        while (pq.size() != 1)
        {
            int first_ele = pq.top(); // extract first element from Priority Queue
            pq.pop();
            int second_ele = pq.top(); // extract second element from Priority Queue
            pq.pop();
            int total = first_ele + second_ele;
            pq.push(total);
            ans += total;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num)
        {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}