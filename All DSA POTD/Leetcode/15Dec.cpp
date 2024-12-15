#include <bits/stdc++.h>
using namespace std;

// C++ 14 Dec
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        // Priority queue to store tuples in descending order of extra pass ratio
        priority_queue<tuple<double, int, int>> maxHeap;

        for (const vector<int> &c : classes)
        {
            const int pass = c[0];
            const int total = c[1];
            maxHeap.emplace(extraPassRatio(pass, total), pass, total);
        }

        for (int i = 0; i < extraStudents; ++i)
        {
            double extraRatio;
            int pass, total;
            tie(extraRatio, pass, total) = maxHeap.top();
            maxHeap.pop();
            maxHeap.emplace(extraPassRatio(pass + 1, total + 1), pass + 1, total + 1);
        }

        double ratioSum = 0.0;

        while (!maxHeap.empty())
        {
            double extraRatio;
            int pass, total;
            tie(extraRatio, pass, total) = maxHeap.top();
            maxHeap.pop();
            ratioSum += pass / static_cast<double>(total);
        }

        return ratioSum / classes.size();
    }

private:
    // Returns the extra pass ratio if a brilliant student joins.
    double extraPassRatio(int pass, int total)
    {
        return (pass + 1) / static_cast<double>(total + 1) -
               pass / static_cast<double>(total);
    }
};

// C++ 20 Solution

/*
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<tuple<double, int, int>> maxHeap;

        for (const vector<int> &c : classes)
        {
            const int pass = c[0];
            const int total = c[1];
            maxHeap.emplace(extraPassRatio(pass, total), pass, total);
        }

        for (int i = 0; i < extraStudents; ++i)
        {
            const auto [_, pass, total] = maxHeap.top();
            maxHeap.pop();
            maxHeap.emplace(extraPassRatio(pass + 1, total + 1), pass + 1, total + 1);
        }

        double ratioSum = 0;

        while (!maxHeap.empty())
        {
            const auto [_, pass, total] = maxHeap.top();
            maxHeap.pop();
            ratioSum += pass / static_cast<double>(total);
        }

        return ratioSum / classes.size();
    }

private:
    // Returns the extra pass ratio if a brilliant student joins.
    double extraPassRatio(int pass, int total)
    {
        return (pass + 1) / static_cast<double>(total + 1) -
               pass / static_cast<double>(total);
    }
};
*/