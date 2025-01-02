#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int countSubarrays(vector<int> &arr, int k)
    {
        // code here
        unordered_map<int, int> mp;
        int count = 0;
        int sum = 0;
        mp[0] = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (mp.find(sum - k) != mp.end())
            {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
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
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}
