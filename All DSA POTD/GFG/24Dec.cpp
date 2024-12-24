#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        int tot = row * col - 1;
        int s = 0;
        int e = tot;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int rIdx = mid / col;
            int cIdx = mid % col;
            if (mat[rIdx][cIdx] == x)
                return true;
            else if (mat[rIdx][cIdx] < x)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return false;
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
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}