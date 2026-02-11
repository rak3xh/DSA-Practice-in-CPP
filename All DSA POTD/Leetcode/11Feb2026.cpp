#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size();
        int sq = sqrt(n);
        int b = (n / sq) + 1;

        // initializating difference array and maximum,minimum arrays and last array.

        vector<int> diff(n, 0);
        vector<int> temp(b, 0), mini(b, 0), maxi(b, 0);
        vector<int> last(100001, -1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            // balance

            int x;
            if (nums[i] % 2 == 0)
                x = 1;
            else
                x = -1;

            // check in the subarray (last[x]+1,i)

            int l = last[nums[i]] + 1;
            int r = i;
            last[nums[i]] = i;

            // range update

            if (l <= r)
            {

                // start and end values in the block

                int bs = l / sq;
                int be = r / sq;

                // the range (l,r) lies inside the block completely

                if (bs == be)
                {
                    int h = min(n, (bs + 1) * sq); // end index
                    int ind = bs * sq;             // start index
                    mini[bs] = INT_MAX;            // to find new min and max
                    maxi[bs] = INT_MIN;

                    // iterate through specific block to update diff.

                    for (int j = ind; j < h; j++)
                    {
                        if (j >= l && j <= r)
                            diff[j] = diff[j] + x;
                        mini[bs] = min(mini[bs], diff[j]);
                        maxi[bs] = max(maxi[bs], diff[j]);
                    }
                }

                // range spans multiple blocks

                else
                {

                    // update partial start block

                    int h1 = (bs + 1) * sq;
                    int ind1 = bs * sq;
                    mini[bs] = INT_MAX;
                    maxi[bs] = INT_MIN;
                    for (int j = ind1; j < h1; j++)
                    {
                        if (j >= l)
                            diff[j] = diff[j] + x;
                        mini[bs] = min(mini[bs], diff[j]);
                        maxi[bs] = max(maxi[bs], diff[j]);
                    }

                    // update full middle blocks

                    for (int k = bs + 1; k < be; k++)
                        temp[k] = temp[k] + x;

                    // update partial end block

                    int h2 = min(n, (be + 1) * sq);
                    int ind2 = be * sq;
                    mini[be] = INT_MAX;
                    maxi[be] = INT_MIN;
                    for (int j = ind2; j < h2; j++)
                    {
                        if (j <= r)
                            diff[j] = diff[j] + x;
                        mini[be] = min(mini[be], diff[j]);
                        maxi[be] = max(maxi[be], diff[j]);
                    }
                }
            }
            bool ok = false;

            // we look for smallest index k

            for (int j = 0; j <= i / sq; j++)
            {
                if (mini[j] + temp[j] > 0 || maxi[j] + temp[j] < 0)
                    continue;

                // iterate through the block

                int h = min(n, (j + 1) * sq);
                int s = j * sq;
                for (int k = s; k < h; k++)
                {
                    if (k > i) // we cannot go beyond i beacause it is right most
                        break;
                    if (diff[k] + temp[j] == 0)
                    {
                        ans = max(ans, i - k + 1);
                        ok = true; // we found so break
                        break;
                    }
                }
                if (ok)
                    break;
            }
        }
        return ans;
    }
};