#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minValue(string s, int k)
    {
        // code here
        int n = s.length();

        vector<int> count(26);
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;

        priority_queue<int> pq;
        for (auto it : count)
            if (it > 0)
                pq.push(it);

        while (k--)
        {
            int tmp = pq.top();
            pq.pop();
            pq.push(--tmp);
        }

        int result = 0;
        while (!pq.empty())
        {
            result += pq.top() * pq.top();
            pq.pop();
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }
    return 0;
}