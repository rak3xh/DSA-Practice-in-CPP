#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        // code here
        vector<int> ans;

        int left = 0;
        int down = mat.size() - 1;
        int right = mat[0].size() - 1;
        int up = 0;

        int turn = 1;
        while (left <= right && up <= down)
        {
            turn = turn % 4;
            if (turn == 1)
            {
                // 1 mtlb up row pr h hum log or printing krenege left or right
                if (left > right)
                    break;

                // right + left hmesha total columns k barabsar hoga
                for (int temp = left; temp <= right; temp++)
                {
                    ans.push_back(mat[up][temp]);
                }
                up++;
                turn++;
            }
            if (turn == 2)
            {
                // 2 mtlb right  column pr h hum log or printing kreneg up or down

                if (up > down)
                    break;
                // up + down hmesha total columns k barabsar hoga
                for (int temp = up; temp <= down; temp++)
                {
                    ans.push_back(mat[temp][right]);
                }
                right--;
                turn++;
            }
            if (turn == 3)
            {
                // 3 mtlb down  row pr h hum log or printing kreneg right or left
                if (left > right)
                    break;

                // right + left hmesha total columns k barabsar hoga
                for (int temp = right; temp >= left; temp--)
                {
                    ans.push_back(mat[down][temp]);
                }
                down--;
                turn++;
            }
            if (turn == 4)
            {
                // 4 mtlb left  colmn pr h hum log or printing kreneg down to up.

                if (up > down)
                    break;
                // up + down hmesha total columns k barabsar hoga
                for (int temp = down; temp >= up; temp--)
                {
                    ans.push_back(mat[temp][left]);
                }
                left++;
                turn++;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}