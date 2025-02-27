#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> v1, v2;
    Solution()
    {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x)
    {
        // code here
        v1.push_back(x);
        if (v1.size() == 1)
            v2.push_back(x);
        else
        {
            if (v2.back() > x)
                v2.push_back(x);
        }
    }

    // Remove the top element from the Stack
    void pop()
    {
        // code here
        int x = -1;
        if (v1.size() > 0)
        {
            if (v1.back() == v2.back())
                v2.pop_back();
            v1.pop_back();
        }
    }

    // Returns top element of the Stack
    int peek()
    {
        // code here
        if (v1.size() > 0)
            return v1.back();
        return -1;
    }

    // Finds minimum element of Stack
    int getMin()
    {
        // code here
        if (v2.size() > 0)
            return v2.back();
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
        int q;
        cin >> q;

        Solution ob;

        while (q--)
        {
            int qt;
            cin >> qt;

            if (qt == 1)
            {
                // push
                int att;
                cin >> att;
                ob.push(att);
            }
            else if (qt == 2)
            {
                // pop
                ob.pop();
            }
            else if (qt == 3)
            {
                // peek
                cout << ob.peek() << " ";
            }
            else if (qt == 4)
            {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}
