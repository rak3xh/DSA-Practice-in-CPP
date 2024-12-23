#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++)
        {
            int lo = 0, hi = m - 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (mat[i][mid] == x)
                    return 1;
                else if (mat[i][mid] < x)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
