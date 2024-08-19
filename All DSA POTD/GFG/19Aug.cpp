#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        // code here
        priority_queue<int> pq;

        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (pq.size() < k)
            {
                pq.push(arr[i]);
            }
            else if (!pq.empty() && pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
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
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}
