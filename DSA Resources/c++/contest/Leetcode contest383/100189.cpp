#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> resultGrid(vector<vector<int>> &image, int threshold)
    {
        auto a = image;

        int k = threshold, n = image.size(), m = image[0].size();

        auto ans = a;

        vector<vector<vector<int>>> st(n, vector<vector<int>>(m));

        for (int i = 0; i < n - 2; i++)
        {

            for (int j = 0; j < m - 2; j++)
            {

                int mx = 0, mn = 256, sm = 0;

                for (int ii = i; ii <= i + 2; ii++)
                {

                    for (int jj = j; jj <= j + 2; jj++)
                    {

                        if (ii != i + 2)
                        {

                            mx = max(mx, abs(a[ii][jj] - a[ii + 1][jj]));
                        }

                        if (jj != j + 2)
                        {

                            mx = max(mx, abs(a[ii][jj] - a[ii][jj + 1]));
                        }

                        sm += a[ii][jj];
                    }
                }

                if (mx > k)
                {

                    continue;
                }

                for (int ii = i; ii <= i + 2; ii++)
                {

                    for (int jj = j; jj <= j + 2; jj++)
                    {

                        st[ii][jj].push_back(sm / 9);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                if (st[i][j].size())
                {

                    int sm = 0;

                    for (int &x : st[i][j])
                    {

                        sm += x;
                    }

                    ans[i][j] = sm / int(st[i][j].size());
                }
            }
        }

        return ans;
    }
};