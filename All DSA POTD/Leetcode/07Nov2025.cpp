#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long left = *min_element(stations.begin(), stations.end());
        long right = accumulate(stations.begin(), stations.end(), 0L) + k + 1;

        while (left < right) {
            const long mid = (left + right) / 2;
            if (check(stations, r, k, mid))
                left = mid + 1;
            else
                right = mid;
        }

        return left - 1;
    }

private:
    // Returns true if each city can have at least `minPower`.
    bool check(vector<int> stations, int r, int additionalStations, long minPower) {
        const int n = stations.size();
        long power = 0;

        // Initialize power = sum(stations[0..r-1])
        for (int i = 0; i < r && i < n; ++i)
            power += stations[i];

        for (int i = 0; i < n; ++i) {
            if (i + r < n)
                power += stations[i + r]; // sum(stations[i - r..i + r])
            if (power < minPower) {
                const long requiredPower = minPower - power;
                if (requiredPower > additionalStations)
                    return false;
                // Place new stations at farthest possible index
                int pos = min(n - 1, i + r);
                stations[pos] += requiredPower;
                additionalStations -= requiredPower;
                power += requiredPower;
            }
            if (i - r >= 0)
                power -= stations[i - r];
        }

        return true;
    }
};
