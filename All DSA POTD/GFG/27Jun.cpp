#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

bool check(int r, int c, vector<vector<int>> &mat)
{
    int val = mat[r][c];
    int n = mat.size();
    int m = mat[0].size();
    while (mat[r][c] == val)
    {
        r++, c++;
        if (r == n || c == m)
            return true;
    }
    return false;
}

bool isToeplitz(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();
    int m = mat[0].size();

    for (int j = 0; j < m - 1; j++)
    {
        int r = 0;
        int c = j;
        if (!check(r, c, mat))
            return false;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int r = i;
        int c = 0;
        if (!check(r, c, mat))
            return false;
    }

    return true;
}