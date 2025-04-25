#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        // code here
        int cnt = 0, ans = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (cnt == 0)
            {
                ans = arr[i];
                cnt = 1;
            }
            else if (arr[i] == ans)
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == ans)
                cnt++;
        }
        if (cnt > arr.size() / 2)
            return ans;
        return -1;
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
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}
