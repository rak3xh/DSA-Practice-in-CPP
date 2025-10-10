#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    vector<int> zigZagTraversal(Node *root)
    {
        // code here
        vector<int> ans;
        queue<Node *> q;
        q.push(root);
        bool f = 0;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                q.pop();
                v.push_back(front->data);

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            if (f)
                reverse(v.begin(), v.end());
            f = !f;
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};