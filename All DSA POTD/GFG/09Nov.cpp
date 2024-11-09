#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string minSum(vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        string odd = "", even;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i % 2 == 0)
            {
                even += to_string(arr[i]);
            }
            else
            {
                odd += to_string(arr[i]);
            }
        }
        reverse(odd.begin(), odd.end());
        reverse(even.begin(), even.end());
        int i = 0, j = 0;
        string ans;
        int carry = 0;
        while (i < odd.length() || j < even.length())
        {
            int sum = 0;
            if (i < odd.length())
            {
                sum += odd[i] - '0';
                i++;
            }
            if (j < even.length())
            {
                sum += even[j] - '0';
                j++;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ans += to_string(sum);
        }
        ans += to_string(carry);
        while (ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
