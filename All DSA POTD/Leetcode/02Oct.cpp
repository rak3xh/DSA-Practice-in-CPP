#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> sortedArr(arr);
        unordered_map<int, int> rank;

        sort(sortedArr.begin(), sortedArr.end());

        for (const int a : sortedArr)
            if (rank.find(a) == rank.end()) // C++14 replacement for rank.contains(a)
                rank[a] = rank.size() + 1;

        for (int &a : arr)
            a = rank[a];

        return arr;
    }
};
