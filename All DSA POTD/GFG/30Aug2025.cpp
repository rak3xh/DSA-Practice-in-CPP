#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        stack<int> s;
        for (int i = 0; i < n; i++)
            s.push(i);
        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            bool f = true;
            for (int i = 0; i < n; i++)
            {
                if (mat[a][i] == 1 && i != a)
                {
                    f = false;
                    break;
                }
            }

            if (mat[b][a] == 1 && f)
            {
                s.push(a);
            }

            f = true;

            for (int i = 0; i < n; i++)
            {
                if (mat[b][i] == 1 && i != b)
                {
                    f = false;
                    break;
                }
            }

            if (mat[a][b] == 1 && f)
            {
                s.push(b);
            }
        }

        if (s.size() == 0)
            return -1;
        int a = s.top();
        s.pop();

        bool f = true;
        for (int i = 0; i < n; i++)
        {
            if (mat[a][i] == 1 && i != a)
            {
                f = false;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (mat[i][a] == 0)
                return -1;
        }
        if (f)
            return a;
        return -1;
    }
};