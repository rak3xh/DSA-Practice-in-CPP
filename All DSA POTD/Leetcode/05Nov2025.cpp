#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        using FreqValuePair = pair<int, int>; // {frequency, value}

        // topX: maintains the top x elements (by frequency, then by value)
        // remaining: maintains elements not in top x
        set<FreqValuePair> topX, remaining;
        long long currentSum = 0;          // Sum of (frequency * value) for elements in topX
        unordered_map<int, int> frequency; // Maps value to its frequency in current window

        // Helper function to add an element to the appropriate set after its frequency changes
        auto addToSets = [&](int value)
        {
            if (frequency[value] == 0)
            {
                return; // Element not in window, nothing to add
            }

            FreqValuePair element = {frequency[value], value};

            // If topX is empty or element is better than worst in topX, add to topX
            if (!topX.empty() && element > *topX.begin())
            {
                currentSum += 1LL * element.first * element.second; // frequency * value
                topX.insert(element);
            }
            else
            {
                remaining.insert(element);
            }
        };

        // Helper function to remove an element from sets before its frequency changes
        auto removeFromSets = [&](int value)
        {
            if (frequency[value] == 0)
            {
                return; // Element not in window, nothing to remove
            }

            FreqValuePair element = {frequency[value], value};

            // Check if element is in topX
            auto it = topX.find(element);
            if (it != topX.end())
            {
                currentSum -= 1LL * element.first * element.second; // frequency * value
                topX.erase(it);
            }
            else
            {
                remaining.erase(element);
            }
        };

        vector<long long> result;

        // Process each element in the array
        for (int i = 0; i < nums.size(); ++i)
        {
            // Update frequency for new element entering window
            removeFromSets(nums[i]); // Remove old frequency entry
            ++frequency[nums[i]];    // Update frequency
            addToSets(nums[i]);      // Add new frequency entry

            // Calculate window start position
            int windowStart = i - k + 1;
            if (windowStart < 0)
            {
                continue; // Window not yet complete
            }

            // Rebalance sets to maintain exactly x elements in topX (if possible)
            // Move elements from remaining to topX if needed
            while (!remaining.empty() && topX.size() < x)
            {
                FreqValuePair best = *remaining.rbegin(); // Get best from remaining
                currentSum += 1LL * best.first * best.second;
                remaining.erase(best);
                topX.insert(best);
            }

            // Move excess elements from topX to remaining if needed
            while (topX.size() > x)
            {
                FreqValuePair worst = *topX.begin(); // Get worst from topX
                currentSum -= 1LL * worst.first * worst.second;
                topX.erase(worst);
                remaining.insert(worst);
            }

            // Add current window's x-sum to result
            result.push_back(currentSum);

            // Remove element leaving the window
            removeFromSets(nums[windowStart]); // Remove old frequency entry
            --frequency[nums[windowStart]];    // Update frequency
            addToSets(nums[windowStart]);      // Add new frequency entry (or nothing if freq becomes 0)
        }

        return result;
    }
};