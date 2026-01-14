#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    explicit SegmentTree(const vector<int> &xs_)
        : xs(xs_), n(xs_.size() - 1),
          coveredCount(4 * n), coveredWidth(4 * n) {}

    // Adds val to the range [i, j].
    void add(int i, int j, int val)
    {
        add(0, 0, n - 1, i, j, val);
    }

    // Returns the covered width of xs[0..n - 1].
    int getCoveredWidth() const
    {
        return coveredWidth[0];
    }

private:
    int n; // number of segments (|xs| - 1)
    vector<int> xs;
    vector<int> coveredCount;
    vector<int> coveredWidth;

    void add(int treeIndex, int lo, int hi, int i, int j, int val)
    {
        if (j <= xs[lo] || xs[hi + 1] <= i)
            return;

        if (i <= xs[lo] && xs[hi + 1] <= j)
        {
            coveredCount[treeIndex] += val;
        }
        else
        {
            int mid = (lo + hi) / 2;
            add(2 * treeIndex + 1, lo, mid, i, j, val);
            add(2 * treeIndex + 2, mid + 1, hi, i, j, val);
        }

        if (coveredCount[treeIndex] > 0)
        {
            coveredWidth[treeIndex] = xs[hi + 1] - xs[lo];
        }
        else if (lo == hi)
        {
            coveredWidth[treeIndex] = 0;
        }
        else
        {
            coveredWidth[treeIndex] =
                coveredWidth[2 * treeIndex + 1] +
                coveredWidth[2 * treeIndex + 2];
        }
    }
};

class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        vector<tuple<int, int, int, int>> events; // (y, delta, xl, xr)
        set<int> xs;

        for (const auto &square : squares)
        {
            int x = square[0];
            int y = square[1];
            int l = square[2];

            events.emplace_back(y, 1, x, x + l);
            events.emplace_back(y + l, -1, x, x + l);

            xs.insert(x);
            xs.insert(x + l);
        }

        sort(events.begin(), events.end());

        double halfArea = getArea(events, xs) / 2.0;

        long area = 0;
        int prevY = 0;

        vector<int> xsVec(xs.begin(), xs.end());
        SegmentTree tree(xsVec);

        for (const auto &e : events)
        {
            int y = get<0>(e);
            int delta = get<1>(e);
            int xl = get<2>(e);
            int xr = get<3>(e);

            int coveredWidth = tree.getCoveredWidth();
            long areaGain = coveredWidth * static_cast<long>(y - prevY);

            if (area + areaGain >= halfArea)
            {
                return prevY + (halfArea - area) / coveredWidth;
            }

            area += areaGain;
            tree.add(xl, xr, delta);
            prevY = y;
        }

        throw runtime_error("Unreachable code");
    }

private:
    long getArea(const vector<tuple<int, int, int, int>> &events,
                 const set<int> &xs)
    {
        long totalArea = 0;
        int prevY = 0;

        vector<int> xsVec(xs.begin(), xs.end());
        SegmentTree tree(xsVec);

        for (const auto &e : events)
        {
            int y = get<0>(e);
            int delta = get<1>(e);
            int xl = get<2>(e);
            int xr = get<3>(e);

            totalArea += tree.getCoveredWidth() * static_cast<long>(y - prevY);
            tree.add(xl, xr, delta);
            prevY = y;
        }

        return totalArea;
    }
};
