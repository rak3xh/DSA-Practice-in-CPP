#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int kthMissing(vector<int> &arr, int k)
    {
        // Your code goes here
        vector<int> missing;
        int num = arr[arr.size() - 1];
        map<int, int> mp;
        if (arr.size() >= num)
        {
            return num + k;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }

        for (int i = 1; i <= num; i++)
        {
            if (mp.find(i) == mp.end())
            {
                missing.push_back(i);
            }
        }
        while (missing.size() < k)
        {
            missing.push_back(num + 1);
            num++;
        }
        return missing.at(k - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--)
    {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}