#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct cmp
    {
        bool operator()(const tuple<int, int, int> &t1,
                        const tuple<int, int, int> &t2) const
        {
            int a = get<0>(t1);
            int b = get<1>(t1);

            int x = get<0>(t2);
            int y = get<1>(t2);

            return a + b > x + y;
        }
    };

    int minTime(vector<int> &ranks, int n)
    {
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            cmp>
            q;

        for (int i : ranks)
            q.push(make_tuple(0, i, i));

        int ans = 0;

        while (n--)
        {
            tuple<int, int, int> t = q.top();
            q.pop();

            int a = get<0>(t);
            int b = get<1>(t);
            int c = get<2>(t);

            a += b;
            b += c;

            ans = max(ans, a);

            q.push(make_tuple(a, b, c));
        }

        return ans;
    }
};
