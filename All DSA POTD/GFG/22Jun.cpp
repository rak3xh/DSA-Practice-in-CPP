#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    bool isNumber(const string &word)
    {
        for (char c : word)
        {
            if (!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }

    bool containsNine(const string &number)
    {
        for (char c : number)
        {
            if (c == '9')
            {
                return true;
            }
        }
        return false;
    }

public:
    long long ExtractNumber(string sentence)
    {

        // code here
        stringstream ss(sentence);
        string word;
        long long largestNumber = -1;

        while (ss >> word)
        {
            if (isNumber(word) && !containsNine(word))
            {
                long long num = stoll(word);
                if (num > largestNumber)
                {
                    largestNumber = num;
                }
            }
        }

        return largestNumber;
    }
};

//{ Driver Code Starts.
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return  0;
}