#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> longestSubarray(vector<int> &arr, int x)
    {
        // code here
        int n = arr.size();
        deque<int> mn, mx;
        int en = 0, st = 0;
        int i = 0, j = 0;

        while (j < n)
        {
            while (!mn.empty() && mn.back() > arr[j])
                mn.pop_back();
            while (!mx.empty() && mx.back() < arr[j])
                mx.pop_back();
            mn.push_back(arr[j]);
            mx.push_back(arr[j]);

            if (mx.front() - mn.front() <= x)
            {
                if ((en - st) < (j - i))
                {
                    en = j;
                    st = i;
                }
                j++;
            }
            else
            { // mx.front()-mn.front()>x
                if (arr[i] == mx.front())
                    mx.pop_front();
                if (arr[i] == mn.front())
                    mn.pop_front();
                i++;
                j++;
            }
        }

        if (en == st)
            return {arr[0]}; // If multiple such subarrays exist, return the one that starts at the smallest inde
        vector<int> res;
        for (int i = st; i <= en; i++)
            res.push_back(arr[i]);
        return res;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}