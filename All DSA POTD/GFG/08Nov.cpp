#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool checkContainsCharacter(const string &s1, const string &s2)
    {
        unordered_map<char, int> ump;
        for (char i : s1)
        {
            ump[i]++;
        }

        for (char ch : s2)
        {
            if (ump.find(ch) == ump.end())
            {
                return false;
            }
        }

        return true;
    }

    bool checkIfSame(const string &s2, const string &repeatString)
    {
        return repeatString.find(s2) != string::npos;
    }
    int minRepeats(string &s1, string &s2)
    {
        // code here
        if (!checkContainsCharacter(s1, s2))
        {
            return -1;
        }

        int s2Length = s2.length();
        int s1Length = s1.length();
        int repeatCount = (s2Length + s1Length - 1) / s1Length;

        string repeatString;
        for (int i = 0; i < repeatCount; i++)
        {
            repeatString += s1;
        }

        if (checkIfSame(s2, repeatString))
        {
            return repeatCount;
        }
        else
        {
            repeatString += s1;
            if (checkIfSame(s2, repeatString))
            {
                return repeatCount + 1;
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}