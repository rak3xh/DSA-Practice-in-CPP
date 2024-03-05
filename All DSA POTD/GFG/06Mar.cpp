#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class ZAlgorithm
{
private:
    string s, p;
    vector<int> z;

public:
    ZAlgorithm(string s, string p)
    {
        this->s = s;
        this->p = p;
        calculateZArray();
    }
    void calculateZArray()
    {
        string zString = p + "#" + s;
        int n = zString.size();
        z.resize(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if (i < r)
                z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && zString[z[i]] == zString[i + z[i]])
                z[i]++;
            if (i + z[i] > r)
                l = i, r = i + z[i];
        }
    }
    vector<int> findAllOccurences()
    {
        vector<int> ZIndices;
        for (int i = 0; i < z.size(); i++)
        {
            if (z[i] == p.size())
            {
                int index = i - p.size() - 1;
                ZIndices.push_back(index + 1);
            }
        }
        return ZIndices;
    }
};

class Solution

{
public:
    vector<int> search(string pattern, string text)
    {
        // code here.
        ZAlgorithm zz(text, pattern);
        vector<int> occurences = zz.findAllOccurences();
        return occurences;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
