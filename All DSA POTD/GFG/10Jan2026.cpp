#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubstr(string &s, int k)
    {
        // code here
        int n = s.size();
        auto f = [&](int k) -> int
        {
            int ans = 0;
            //  unordered_map<char,int> m;
            //   map<char,int> m;
            vector<int> m(26, 0);
            int cnt = 0;
            for (int i = 0, j = 0; i < n; i++)
            {
                if (m[s[i] - 'a'] == 0)
                    cnt++;
                m[s[i] - 'a']++;

                while (cnt >= k)
                {
                    ans += n - i;
                    m[s[j] - 'a']--;
                    if (m[s[j] - 'a'] == 0)
                        cnt--;

                    j++;
                }
            }
            return ans;
        };
        return f(k) - f(k + 1);
    }
};