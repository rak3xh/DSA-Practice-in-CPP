#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
         int n = s.length();
        int sum = 1, pval = 1, ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            ans += ((i + 1) * ((s[i] - '0') * sum));
            pval *= 10;
            sum += pval;
        }
        return ans;
    }
};