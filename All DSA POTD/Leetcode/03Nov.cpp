#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    }
};