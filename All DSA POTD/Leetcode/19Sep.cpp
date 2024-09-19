#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        unordered_map<string, vector<int>> mem; // Initialize the memoization map
        return ways(expression, mem);
    }

private:
    vector<int> ways(const string &s, unordered_map<string, vector<int>> &mem)
    {
        if (mem.find(s) != mem.end())
            return mem[s];

        vector<int> ans;

        for (int i = 0; i < s.length(); ++i)
        {
            if (ispunct(s[i]))
            {
                vector<int> left = ways(s.substr(0, i), mem);
                vector<int> right = ways(s.substr(i + 1), mem);
                for (const int a : left)
                {
                    for (const int b : right)
                    {
                        if (s[i] == '+')
                            ans.push_back(a + b);
                        else if (s[i] == '-')
                            ans.push_back(a - b);
                        else if (s[i] == '*')
                            ans.push_back(a * b);
                    }
                }
            }
        }

        if (ans.empty())
            ans.push_back(stoi(s));

        mem[s] = ans;
        return ans;
    }
};