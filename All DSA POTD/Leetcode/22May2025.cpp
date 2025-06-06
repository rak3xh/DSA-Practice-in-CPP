#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        int queryIndex = 0;
        priority_queue<int> available;                       // available `r`s
        priority_queue<int, vector<int>, greater<>> running; // running `r`s

        sort(queries.begin(), queries.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            while (queryIndex < queries.size() && queries[queryIndex][0] <= i)
                available.push(queries[queryIndex++][1]);
            while (!running.empty() && running.top() < i)
                running.pop();
            while (nums[i] > running.size())
            {
                if (available.empty() || available.top() < i)
                    return -1;
                running.push(available.top()), available.pop();
            }
        }

        return available.size();
    }
};
// C++ 20 SOlution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        int queryIndex = 0;
        priority_queue<int> available;                       // available `r`s
        priority_queue<int, vector<int>, greater<>> running; // running `r`s

        ranges::sort(queries);

        for (int i = 0; i < nums.size(); ++i)
        {
            while (queryIndex < queries.size() && queries[queryIndex][0] <= i)
            available.push(queries[queryIndex++][1]);
            while (!running.empty() && running.top() < i)
            running.pop();
            while (nums[i] > running.size())
            {
                if (available.empty() || available.top() < i)
                return -1;
                running.push(available.top()), available.pop();
            }
        }

        return available.size();
    }
};
*/