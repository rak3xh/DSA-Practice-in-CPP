#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// Position this line where user code will be pasted.
class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        // code here
        int n = arr1.size();
        int m = arr2.size();
        vector<int> ans(n + m);

        for (int i = 0; i < n; i++)
        {
            ans[i] = arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            ans[n + i] = arr2[i];
        }

        sort(ans.begin(), ans.end());

        int rans = ans[(n + m) / 2 - 1] + ans[(n + m) / 2];

        return rans;
    }
};

//{ Driver Code Starts.
// Back-end complete function template in C++

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1)
        {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2)
        {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}