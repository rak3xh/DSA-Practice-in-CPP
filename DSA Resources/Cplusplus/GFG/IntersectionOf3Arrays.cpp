#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find common elements in three arrays.
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2)
    {
        set<int> s1(arr1.begin(), arr1.end());
        set<int> s2(arr2.begin(), arr2.end());
        vector<int> ans;
        for (auto i : s1)
        {
            if (s2.find(i) != s2.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3)
    {
        // Code Here
        vector<int> inter1_2 = intersection(arr1, arr2);
        return intersection(arr3, inter1_2);
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
        vector<int> arr, brr, crr;
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
        string input3;
        getline(cin, input3);
        stringstream ss3(input3);
        int number3;
        while (ss3 >> number3)
        {
            crr.push_back(number3);
        }
        Solution ob;
        vector<int> res = ob.commonElements(arr, brr, crr);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl
             << "~\n";
    }
}