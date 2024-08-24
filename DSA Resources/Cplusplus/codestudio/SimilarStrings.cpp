#include <bits/stdc++.h>

using namespace std;

vector<int> similarStrings(int strLength, string strA, string strB, string strC)
{

    int smallestDiff = INT_MAX;

    int largestDiff = INT_MIN;

    for (int rotation = 0; rotation < strLength; rotation++)
    {

        int totalDiff = 0;

        for (int charIndex = 0; charIndex < strLength; charIndex++)
        {

            totalDiff += abs(strA[(rotation + charIndex) % strLength] - strB[charIndex]) + abs(strA[(rotation + charIndex) % strLength] - strC[charIndex]);
        }

        smallestDiff = min(smallestDiff, totalDiff);

        largestDiff = max(largestDiff, totalDiff);
    }

    return {largestDiff, smallestDiff};
}
