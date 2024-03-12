#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        // Your code here
        //  Be aware of edge cases
        vector<int> ans;
        int n = mat.size();

        int diag = 2 * n - 1; // total diagonal
        int r = 0, c = 0;
        while (diag--)
        {

            if ((r + c) & 1) // odd : r++,c-- moving down
            {
                while (r < n && c >= 0)
                    ans.push_back(mat[r++][c--]);
                if (r == n)
                    c += 2, r -= 1;
                else
                    c++;
            }
            else
            { // even : r--,c++ :: moving up
                while (r >= 0 && c < n)
                    ans.push_back(mat[r--][c++]);
                if (c == n)
                    r += 2, c -= 1;
                else
                    r++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        int k = 0;
        // cin>>k;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int> ans = obj.matrixDiagonally(mat);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
}