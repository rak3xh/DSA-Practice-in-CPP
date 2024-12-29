#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> intersectionWithDuplicates(vector<int> &a, vector<int> &b)
    {
        // code here
        unordered_map<int, int> mp;
        for (auto it : a)
        {
            mp[it]++;
        }

        vector<int> store;
        for (auto it : b)
        {
            if (mp.find(it) != mp.end() && mp[it] > 0)
            {
                store.push_back(it);
                mp[it]--;
                if (mp[it] == 0)
                {
                    mp.erase(it);
                }
            }
        }
        sort(store.begin(), store.end());
        store.erase(unique(store.begin(), store.end()), store.end());
        return store;
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
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number)
        {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0)
        {
            cout << "[]" << endl;
        }
        else
        {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}