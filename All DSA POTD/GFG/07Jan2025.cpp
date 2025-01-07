#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        // Complete the function
        int n = arr.size();
        int s = 0, e = n - 1;
        int count = 0;
        while (s < e)
        {
            int sum = arr[s] + arr[e];
            if (sum > target)
            {
                e--;
            }
            else if (sum < target)
            {
                s++;
            }
            else
            {
                count++;
                int nst = s + 1;
                while (nst < e && arr[nst] == arr[nst - 1])
                {
                    nst++;
                    count++;
                }
                e--;
            }
        }
        return count;
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
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}