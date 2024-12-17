#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool PossibleSolution(vector<int> &stalls, int k, int mid)
    {
        int n = stalls.size();
        int CowsCount = 1;
        int LastPosition = stalls[0];
        for (int i = 0; i < n; i++)
        {
            if ((stalls[i] - LastPosition) >= mid)
            {
                CowsCount++;
                if (CowsCount == k)
                {
                    return true;
                }
                LastPosition = stalls[i];
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {

        // Write your code here
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int s = 0;
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, stalls[i]);
        }
        int e = maxi;
        int mid = s + (e - s) / 2;
        int ans = 0;
        while (s <= e)
        {
            if (PossibleSolution(stalls, k, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
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

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num)
        {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
