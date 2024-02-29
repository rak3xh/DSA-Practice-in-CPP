#include <bits/stdc++.h>
using namespace std;

struct Query
{

    int type; // Type of query

    int l, r; // Range for query of type-1

    int idx; // Index to change for query of type-2
};

vector<int> sgt, pw;

void build(string &s, int l, int r, int i)
{
    if (l == r)
    {
        sgt[i] = s[l] - '0';
        return;
    }

    int m = (l + r) / 2;
    build(s, l, m, 2 * i + 1);
    build(s, m + 1, r, 2 * i + 2);

    // Combine left subtree and right subtree by shifting the left substree to the left.
    sgt[i] = (sgt[2 * i + 1] * pw[r - m] + sgt[2 * i + 2]) % 3;
}

void update(int l, int r, int id, int i)
{
    if (l > id || r < id)
    {
        return;
    }
    if (l == r)
    {
        // Flip the bit
        sgt[i] = 1 - sgt[i];
        return;
    }

    int m = (l + r) / 2;
    update(l, m, id, 2 * i + 1);
    update(m + 1, r, id, 2 * i + 2);

    // Combine again as change might have occured in the subtrees
    sgt[i] = (sgt[2 * i + 1] * pw[r - m] + sgt[2 * i + 2]) % 3;
}

int query(int l, int r, int a, int b, int i)
{
    if (l > b || r < a)
        return 0;

    if (l >= a && r <= b)
    {
        // Return the binary equivalent after shifting it to the right.
        return (sgt[i] * pw[b - r]) % 3;
    }

    int m = (l + r) / 2;

    int lq = query(l, m, a, b, 2 * i + 1);
    int rq = query(m + 1, r, a, b, 2 * i + 2);

    return (lq + rq) % 3;
}

vector<int> binaryFlip(int n, string &s, int q, vector<Query> &queries)
{
    sgt.clear();
    pw.clear();

    sgt.resize(4 * n); // Maximum size segtree can be formed
    pw.resize(n);

    // Precalculate (2^i)%3 for faster calculation
    pw[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pw[i] = (pw[i - 1] * 2) % 3;
    }

    // Build seg tree from input
    build(s, 0, n - 1, 0);

    vector<int> res;
    for (int i = 0; i < q; i++)
    {
        if (queries[i].type == 1)
        {
            int ans = query(0, n - 1, queries[i].l, queries[i].r, 0);
            res.push_back(ans);
        }
        else
        {
            update(0, n - 1, queries[i].idx, 0);
        }
    }

    return res;
}
