#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target,
                          vector<string> &original,
                          vector<string> &changed,
                          vector<int> &cost)
    {

        unordered_set<int> subLengths = getSubLengths(original);
        unordered_map<string, int> subToId = getSubToId(original, changed);
        int subCount = subToId.size();

        // dist[u][v] := min cost to convert substring u -> v
        vector<vector<long>> dist(subCount, vector<long>(subCount, LONG_MAX));

        // dp[i] := min cost to convert source[0..i)
        vector<long> dp(source.length() + 1, LONG_MAX);

        // Initialize transformation costs
        for (int i = 0; i < (int)cost.size(); ++i)
        {
            int u = subToId[original[i]];
            int v = subToId[changed[i]];
            dist[u][v] = min(dist[u][v], (long)cost[i]);
        }

        // Floyd–Warshall to compute all-pairs min transform cost
        for (int k = 0; k < subCount; ++k)
        {
            for (int i = 0; i < subCount; ++i)
            {
                if (dist[i][k] == LONG_MAX)
                    continue;
                for (int j = 0; j < subCount; ++j)
                {
                    if (dist[k][j] == LONG_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        dp[0] = 0;

        // DP over source string
        for (int i = 0; i < (int)source.length(); ++i)
        {
            if (dp[i] == LONG_MAX)
                continue;

            // If characters match, no cost
            if (source[i] == target[i])
            {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Try substring replacements
            for (int subLength : subLengths)
            {
                if (i + subLength > (int)source.length())
                    continue;

                string subSource = source.substr(i, subLength);
                string subTarget = target.substr(i, subLength);

                if (subToId.find(subSource) == subToId.end() ||
                    subToId.find(subTarget) == subToId.end())
                    continue;

                int u = subToId[subSource];
                int v = subToId[subTarget];

                if (dist[u][v] != LONG_MAX)
                {
                    dp[i + subLength] = min(dp[i + subLength], dp[i] + dist[u][v]);
                }
            }
        }

        return dp[source.length()] == LONG_MAX ? -1 : dp[source.length()];
    }

private:
    unordered_map<string, int> getSubToId(const vector<string> &original,
                                          const vector<string> &changed)
    {
        unordered_map<string, int> subToId;

        for (int i = 0; i < (int)original.size(); ++i)
        {
            if (subToId.find(original[i]) == subToId.end())
            {
                subToId[original[i]] = subToId.size();
            }
        }

        for (int i = 0; i < (int)changed.size(); ++i)
        {
            if (subToId.find(changed[i]) == subToId.end())
            {
                subToId[changed[i]] = subToId.size();
            }
        }

        return subToId;
    }

    unordered_set<int> getSubLengths(const vector<string> &original)
    {
        unordered_set<int> subLengths;

        for (int i = 0; i < (int)original.size(); ++i)
        {
            subLengths.insert(original[i].length());
        }

        return subLengths;
    }
};
