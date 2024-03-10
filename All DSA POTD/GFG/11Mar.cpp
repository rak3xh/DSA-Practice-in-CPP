#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        // Your code goes here
        int count = 0;
        int s1 = 0, s2 = n - 1;
        int i = 0, j = n - 1;

        while (i < n && j >= 0)
        {
            int temp = mat1[i][s1] + mat2[j][s2];
            if (temp == x)
            {
                count++;
                s1++;
                s2--;
            }
            else if (temp > x)
            {
                s2--;
            }
            else
            {
                s1++;
            }

            if (s1 == n)
            {
                s1 = 0;
                i++;
            }

            if (s2 == -1)
            {
                s2 = n - 1;
                j--;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat1[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat2[i][j];
            }
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";
    }

    return 0;
}