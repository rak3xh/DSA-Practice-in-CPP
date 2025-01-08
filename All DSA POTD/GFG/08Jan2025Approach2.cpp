#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int count = 0;

        // If there are fewer than 3 elements, no triangles can be formed
        if (n < 3)
        {
            return 0;
        }

        // Sort the array
        sort(arr.begin(), arr.end());

        // Iterate through the array from the end to the third element
        for (int i = n - 1; i >= 2; --i)
        {
            int left = 0;
            int right = i - 1;

            while (left < right)
            {
                int sum = arr[left] + arr[right];

                if (sum > arr[i])
                {
                    // If the sum of arr[left] and arr[right] is greater than arr[i],
                    // all elements between left and right can form a triangle with arr[i]
                    count += (right - left);
                    --right;
                }
                else
                {
                    ++left;
                }
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
    cin.ignore(); // To ignore the newline after the integer input
    while (t--)
    {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}
