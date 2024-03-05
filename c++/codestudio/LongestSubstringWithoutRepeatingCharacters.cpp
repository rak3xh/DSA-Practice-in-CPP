#include <bits/stdc++.h>
using namespace std;
int uniqueSubstrings(string s)
{

    int maxlen = 0, mask = 0;

    for (int l = 0, r = 0; r < s.size(); r++)
    {

        while (mask >> s[r] - 'a' & 1)
            mask ^= (1 << s[l++] - 'a');

        mask |= (1 << s[r] - 'a');

        maxlen = max(maxlen, r - l + 1);
    }

    return maxlen;
}
