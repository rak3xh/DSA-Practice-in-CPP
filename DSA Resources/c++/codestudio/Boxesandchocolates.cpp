#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int subsequenceOf3(vector<int> &arr, int n)
{

    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][arr[0] % 3] = dp[0][arr[0] % 3] + 1;

    for (int i = 1; i < n; i++)
    {

        vector<int> temp(3, 0);

        temp[arr[i] % 3] = temp[arr[i] % 3] + 1;

        for (int j = 0; j < 3; j++)
        {

            temp[(arr[i] + j) % 3] = (temp[(arr[i] + j) % 3] + dp[i - 1][j]) % mod;
        }

        for (int j = 0; j < 3; j++)
        {

            dp[i][j] = (dp[i - 1][j] + temp[j]) % mod;
        }
    }

    return dp[n - 1][0];
}

int subarrayOf3(vector<int> &arr, int n)
{

    int count = 0, sum = 0;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {

        sum = sum + arr[i];

        if (sum % 3 == 0)
        {

            count = count + 1;
        }

        int x = sum % 3;

        if (mp.find(x) != mp.end())
        {

            count = count + mp[x];
        }

        mp[x] = mp[x] + 1;
    }

    return count;
}

struct node
{

    long long rem0 = 0, rem1 = 0, rem2 = 0;
};

node merge(node n1, node n2)
{

    node nn;

    nn.rem0 = ((n1.rem0 * n2.rem0) % mod + (n1.rem1 * n2.rem2) % mod + (n1.rem2 * n2.rem1) % mod + n1.rem0 + n2.rem0) % mod;

    nn.rem1 = ((n1.rem0 * n2.rem1) % mod + (n1.rem1 * n2.rem0) % mod + n1.rem1 + n2.rem1 + (n1.rem2 * n2.rem2) % mod) % mod;

    nn.rem2 = ((n1.rem0 * n2.rem2) % mod + (n1.rem2 * n2.rem0) % mod + n1.rem2 + n2.rem2 + (n1.rem1 * n2.rem1) % mod) % mod;

    return nn;
}

void build(vector<node> &st, int ss, int se, int ind, vector<int> arr)
{

    if (ss == se)
    {

        node nn;

        nn.rem0 = arr[ss] % 3 == 0 ? 1 : 0;

        nn.rem1 = arr[ss] % 3 == 1 ? 1 : 0;

        nn.rem2 = arr[ss] % 3 == 2 ? 1 : 0;

        st[ind] = nn;

        return;
    }

    int mid = ss + (se - ss) / 2;

    build(st, ss, mid, 2 * ind + 1, arr);

    build(st, mid + 1, se, 2 * ind + 2, arr);

    st[ind] = merge(st[2 * ind + 1], st[2 * ind + 2]);
}

void update(vector<node> &st, int ss, int se, int i, int ind, int val)
{

    if (ss == se)
    {

        node nn;

        nn.rem0 = val % 3 == 0 ? 1 : 0;

        nn.rem1 = val % 3 == 1 ? 1 : 0;

        nn.rem2 = val % 3 == 2 ? 1 : 0;

        st[ind] = nn;

        return;
    }

    int mid = ss + (se - ss) / 2;

    if (i <= mid)
    {

        update(st, ss, mid, i, 2 * ind + 1, val);
    }

    else
    {

        update(st, mid + 1, se, i, 2 * ind + 2, val);
    }

    st[ind] = merge(st[2 * ind + 1], st[2 * ind + 2]);
}

node query(vector<node> &st, int ss, int se, int qs, int qe, int ind)
{

    if (qe < ss || se < qs)
    {

        node nn;

        return nn;
    }

    if (qs <= ss && se <= qe)
    {

        return st[ind];
    }

    int mid = ss + (se - ss) / 2;

    node n1 = query(st, ss, mid, qs, qe, 2 * ind + 1);

    node n2 = query(st, mid + 1, se, qs, qe, 2 * ind + 2);

    return merge(n1, n2);
}

vector<vector<int>> maxNumberOfWays(vector<int> &arr, int n, int q, vector<vector<int>> &queries)
{

    int maxWaysAnyOrder = subsequenceOf3(arr, n);

    int maxWaysConsecutiveOrder = subarrayOf3(arr, n);

    vector<int> queryResult;

    vector<node> st(4 * n + 1);

    build(st, 0, n - 1, 0, arr);

    for (int i = 0; i < q; i++)
    {

        if (queries[i][0] == 0)
        {

            update(st, 0, n - 1, queries[i][1] - 1, 0, queries[i][2]);
        }

        else
        {

            node nn = query(st, 0, n - 1, queries[i][1] - 1, queries[i][2] - 1, 0);

            queryResult.push_back(nn.rem0);
        }
    }

    return {{maxWaysAnyOrder}, {maxWaysConsecutiveOrder}, queryResult};
}