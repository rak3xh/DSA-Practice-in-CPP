#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countTriplets(vector<int> &arr, int target)
    {
        // Code Here
        int ans = 0;
        unordered_map<int, int> m;
        for (auto &i : arr)
            m[i]++;
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]--;
            for (int j = i - 1; j >= 0; j--)
            {

                if (m.find(target - (arr[i] + arr[j])) != m.end())
                    ans += m[target - (arr[i] + arr[j])];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num)
    {
        arr.push_back(num);
    }
    return arr;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}