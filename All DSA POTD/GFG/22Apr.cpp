#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minRow(int n, int m, vector<vector<int>> a)
    {
        // code here
        int mini = INT_MAX; // declaration of mini var.
        int cnt;            // count
        int flag;           // flag

        for (int i = 0; i < n; i++)
        {
            cnt = 0;

            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1) // if element=1 found then increment cnt
                {
                    cnt++;
                }
            }

            if (cnt < mini) // if cnt<mini then update mini and flag
            {
                mini = cnt;
                flag = i + 1; // since row we have to return is in 1 based indexing so i+1
            }
        }
        // return flag;
        return flag; // flag is our answer since we have to return row number
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}