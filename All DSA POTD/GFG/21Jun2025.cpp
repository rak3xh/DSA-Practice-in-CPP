#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int catchThieves(vector<char> &arr, int k)
    {
        // Code here
        int n = arr.size();
        queue<int> police;
        queue<int> thief;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 'P')
            {
                if (thief.empty())
                {
                    police.push(i);
                }
                else
                {
                    while (thief.empty() == false && thief.front() + k < i)
                    {
                        thief.pop();
                    }
                    if (thief.empty() == false)
                    {
                        thief.pop();
                        ans++;
                    }
                }
            }
            else
            {
                if (police.empty())
                {
                    thief.push(i);
                }
                else
                {
                    while (police.empty() == false && police.front() + k < i)
                    {
                        police.pop();
                    }
                    if (police.empty() == false)
                    {
                        police.pop();
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};