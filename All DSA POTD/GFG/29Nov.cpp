#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string addBinary(string &s1, string &s2)
    {
        // your code here
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        string ans = "";
        int carry = 0;
        while (i >= 0 && j >= 0)
        {
            if (s1[i] == '1' && s2[j] == '1')
            {
                if (carry == 1)
                {
                    ans.insert(ans.begin(), '1');
                    carry = 1;
                }
                else
                {

                    ans.insert(ans.begin(), '0');
                    carry = 1;
                }
            }
            else if ((s1[i] == '0' && s2[j] == '1') || (s1[i] == '1' && s2[j] == '0'))
            {
                if (carry == 1)
                {
                    ans.insert(ans.begin(), '0');
                    carry = 1;
                }
                else
                {
                    ans.insert(ans.begin(), '1');
                }
            }
            else
            {
                if (carry == 1)
                {
                    ans.insert(ans.begin(), '1');
                    carry = 0;
                }
                else
                {
                    ans.insert(ans.begin(), '0');
                }
            }
            i--;
            j--;
        }
        while (i >= 0)
        {
            if (s1[i] == '1')
            {
                if (carry == 1)
                {
                    ans.insert(ans.begin(), '0');
                    carry = 1;
                }
                else
                {
                    ans.insert(ans.begin(), '1');
                }
            }
            else
            {
                if (carry == 1)
                {
                    ans.insert(ans.begin(), '1');
                    carry = 0;
                }
                else
                {
                    ans.insert(ans.begin(), '0');
                }
            }
            i--;
        }
        while (j >= 0)
        {
            if (s2[j] == '1')
            {
                if (carry == 1)
                {
                    ans.insert(ans.begin(), '0');
                    carry = 1;
                }
                else
                {
                    ans.insert(ans.begin(), '1');
                }
            }
            else
            {
                if (carry == 1)
                {
                    ans.insert(ans.begin(), '1');
                    carry = 0;
                }
                else
                {
                    ans.insert(ans.begin(), '0');
                }
            }
            j--;
        }
        if (carry == 1)
            ans.insert(ans.begin(), '1');

        int k = 0;
        while (ans[k] != '1' && k < ans.length())
        {

            k++;
        }
        if (k != 0)
        {
            ans.erase(0, k);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}
