#include <bits/stdc++.h>
using namespace std;
/*    Time Complexity: O(M*(2^M))    Space Complexity: O(2^M)
Where M is the maximumNumber given. */

bool makeTonyWin(int maximumNumber, int target)
{ // Calculating the maximum sum possible.
    int sumOfNumbers = (maximumNumber * (maximumNumber + 1)) / 2;

    // Base Conditions.
    if (target <= 1)
    {
        return 1;
    }

    if (sumOfNumbers < target)
    {
        return 0;
    }

    if (sumOfNumbers == target)
    {
        return maximumNumber % 2;
    }
    int maxStates = 1 << maximumNumber;

    // Storing the calculated answers.
    vector<int> dp(maxStates, 0);

    for (int i = 1; i < maxStates; i++)
    { // Calculating the sum of numbers used till now and storing in variable 'calculateTotal'.
        int calculateTotal = 0, currentDigit = 1, currentState = i;

        while (currentState > 0)
        {
            if ((currentState & 1) > 0)
            {
                calculateTotal += currentDigit;
            }
            currentDigit++;
            currentState >>= 1;
        }

        int usedTillNow = sumOfNumbers - calculateTotal;

        // Number required to win.
        int currentDesired = target - usedTillNow;
        if (currentDesired <= 0)
        {
            continue;
        }

        dp[i] = -1;

        // Iterate over all the unused numbers.
        for (int j = 1; j <= maximumNumber; j++)
        {
            int currentDigit = 1 << (j - 1);
            if ((i & currentDigit) > 0)
            {
                int previousState = i - currentDigit;

                // If the current player can win after choosing the current number or the opponent lost the previous turn.
                if (j >= currentDesired || dp[previousState] == -1)
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }

    // Return the answer of the last possible state as the final answer.
    return dp[maxStates - 1] > 0;
}
