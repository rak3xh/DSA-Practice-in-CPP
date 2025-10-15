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
    void inorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    int kthSmallest(Node *root, int k)
    {
        // code here
        vector<int> ans;
        inorder(root, ans);
        int n = ans.size();

        if (k > n)
            return -1;

        return ans[k - 1];
    }
};