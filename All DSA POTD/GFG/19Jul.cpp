#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution
{
public:
    vector<int> bits;
    void update(int i)
    {
        for (; i < bits.size(); i += (i & (-i)))
        {
            bits[i] += 1;
        }
    }
    int sum(int i)
    {
        int total = 0;
        for (; i > 0; i -= (i & (-i)))
        {
            total += bits[i];
        }
        return total;
    }
    vector<int> constructLowerArray(vector<int> &arr)
    {
        // code here
        map<int, int> mp;
        bits.resize(arr.size() + 3, 0);
        for (int &val : arr)
            mp[val] = 0;
        int count = 1;
        for (auto &pt : mp)
            pt.second = count++;
        for (int &val : arr)
            val = mp[val];
        int n = arr.size();
        vector<int> soln(n);
        for (int i = n - 1; i >= 0; i--)
        {
            soln[i] = sum(arr[i] - 1);
            update(arr[i]);
        }
        return soln;
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}