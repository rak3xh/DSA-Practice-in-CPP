#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    template <typename T>
    void dis(T pq)
    {
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    }
    vector<double> getMedian(vector<int> &arr)
    {
        // code here
        vector<double> ans;
        priority_queue<int> sh;
        priority_queue<int, vector<int>, greater<int>> lh;

        for (auto i : arr)
        {
            sh.push(i);
            if ((sh.size() - lh.size() > 1 || sh.size() - lh.size() < -1))
            {
                if (!sh.empty() && (sh.size() > lh.size()))
                {
                    auto t = sh.top();
                    sh.pop();
                    lh.push(t);
                }
                if (!lh.empty() && (lh.size() > sh.size()))
                {
                    auto t = lh.top();
                    lh.pop();
                    sh.push(t);
                }
            }
            if (!sh.empty() && !lh.empty() && (sh.top() > lh.top()))
            {
                auto t = sh.top();
                sh.pop();
                lh.push(t);
            }

            if (sh.size() > lh.size())
            {

                ans.emplace_back(sh.top());
            }
            else if (sh.size() < lh.size())
            {
                ans.emplace_back(lh.top());
            }
            else
            {

                auto s = sh.top(), l = lh.top();

                ans.emplace_back((s + l) / 2.0);
            }
        }

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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num)
        {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}