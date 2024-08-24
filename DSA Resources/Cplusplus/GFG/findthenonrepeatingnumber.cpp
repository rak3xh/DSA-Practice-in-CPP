#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x ^= nums[i];
        }
        int last_set = 0;
        for (int i = 0; i < 32; i++)
            if ((x >> i) & 1 == 1)
            {
                last_set = i;
                break;
            }
        int num1 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] >> last_set) & 1 == 1)
            {
                num1 ^= nums[i];
            }

            else
                num2 ^= nums[i];
        }
        if (num1 > num2)
            swap(num1, num2);
        return {num1, num2};
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}