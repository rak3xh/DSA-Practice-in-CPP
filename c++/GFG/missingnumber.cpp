#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &array, int n)
    {
        // Your code goes here
        int num = 1;
        sort(array.begin(), array.end());
        for (int i = 0; i < n; i++)
        {
            if (num == array[i])
            {
                num++;
            }
            else
            {
                return num;
            }
        }
    }
};