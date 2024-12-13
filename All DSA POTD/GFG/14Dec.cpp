#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        // complete the function here
        // complete the function here
        // l: The starting index
        // h: The ending index, you have to search the key in this range

        // complete the function here
        int l = 0, h = arr.size() - 1;
        int mid;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (arr[mid] == key)
                return mid;
            // Identify which half portion of array is sorted
            if (arr[l] <= arr[mid])
            { // first half is sorted
                if (arr[l] <= key and key <= arr[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else
            { // second half is sorted
                if (arr[mid] <= key and key <= arr[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}