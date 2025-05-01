#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> nthRowOfPascalTriangle(int n)
    {
        // code here
        vector<int> prev(1, 1);
        if (n == 1)
        {
            return prev;
        }
        vector<int> curr;
        for (int i = 2; i <= n; i++)
        {
            curr.resize(i);
            // the first and last element of this will be 1..
            curr[0] = 1;
            curr[i - 1] = 1;
            for (int j = 1; j < i - 1; j++)
            {
                curr[j] = prev[j - 1] + prev[j];
            }
            prev = curr;
        }
        return prev;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans)
{
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}
