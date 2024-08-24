#include <bits/stdc++.h>
using namespace std;

class NumArray
{
private:
    std::vector<int> arr;

public:
    // Initialize here.
    NumArray(std::vector<int> &arr, int n)
    {
        this->arr = arr;
    }

    // Update operation.
    void update(int l, int r, int val)
    {
        int x = 0;
        for (int i = l - 1; i < r; i++)
        {
            arr[i] += (x + val);
            x++;
        }
    }

    // Return the sum of subarray arr[l..r].
    long long rangeSum(int l, int r)
    {
        long long s = 0;
        for (int i = l - 1; i < r; i++)
        {
            s += arr[i];
        }
        return s;
    }
};