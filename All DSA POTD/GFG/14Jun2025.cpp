#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{
public:
    void inorder(vector<int> &ans, Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(ans, root->left);
        ans.push_back(root->data);
        inorder(ans, root->right);
    }
    bool isSymmetric(Node *root)
    {
        // Code here
        bool ansi = true;
        vector<int> ans;
        inorder(ans, root);
        int i = 0;
        int j = ans.size() - 1;
        while (i <= j)
        {
            if (ans[i] != ans[j])
            {
                ansi = false;
                break;
            }
            i++;
            j--;
        }
        return ansi;
    }
};