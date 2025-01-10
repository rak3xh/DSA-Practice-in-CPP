#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        // code here
        vector<int> res;
        int maximum = arr[arr.size() - 1];
        int flag = 0;
        res.push_back(maximum);
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            if (arr[i] < maximum)
            {
                sort(res.begin(), res.end());
                int a = *upper_bound(res.begin(), res.end(), arr[i]);
                res.erase(std::remove(res.begin(), res.end(), a), res.end());
                res.push_back(arr[i]);
                arr[i] = a;
                i++;
                sort(res.begin(), res.end());
                int j = 0;
                for (; i < arr.size(); i++)
                {
                    arr[i] = res[j];
                    j++;
                }
                flag = 1;
                break;
            }
            else
            {
                res.push_back(arr[i]);
                maximum = arr[i];
            }
        }
        if (!flag)
        {
            reverse(arr.begin(), arr.end());
        }
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
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
