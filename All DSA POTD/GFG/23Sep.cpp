#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        int miss = 0;
        int repeat = 0;
        bool flag = false;
        int actualSum = 0;
        int arrSum = 0;

        // for repeated no

        for (int i = 0; i < arr.size(); i++)
        {
            if ((arr[abs(arr[i]) - 1]) < 0)
            {
                repeat = abs(arr[i]);
                break;
            }
            else
            {
                arr[abs(arr[i]) - 1] = arr[abs(arr[i]) - 1] * -1;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            actualSum += i + 1;
            arrSum += abs(arr[i]);
        }
        // cout<<actualSum<<" "<<arrSum<<" "<<endl;
        int diff = (actualSum - arrSum);

        return {repeat, diff + repeat};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}