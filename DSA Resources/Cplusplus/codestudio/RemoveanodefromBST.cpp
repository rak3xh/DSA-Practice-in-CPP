#include <bits/stdc++.h>
using namespace std;

//  Following is the TreeNode class structure

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int> *getMin(TreeNode<int> *root)
{
    TreeNode<int> *temp = root;
    while (root->left)
    {
        temp = temp->left;
    }
    return temp;
}

TreeNode<int> *getMax(TreeNode<int> *root)
{
    TreeNode<int> *temp = root;
    while (root->right)
    {
        temp = temp->right;
    }
    return temp;
}

int height(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

TreeNode<int> *solve(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->val == x)
    {
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        if (root->left && !root->right)
        {
            TreeNode<int> *temp = root->left;
            root->left = NULL;
            delete root;
            return temp;
        }

        if (!root->left && root->right)
        {
            TreeNode<int> *temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        }

        if (root->left && root->right)
        {
            if (height(root->left) > height(root->right))
            {
                int maxi = getMax(root->left)->val;
                root->val = maxi;
                root->left = solve(root->left, maxi);
                return root;
            }
            else
            {
                int mini = getMin(root->right)->val;
                root->val = mini;
                root->right = solve(root->right, mini);
                return root;
            }
        }
    }
    else if (root->val > x)
    {
        root->left = solve(root->left, x);
        return root;
    }
    else
    {
        root->right = solve(root->right, x);
        return root;
    }
}

TreeNode<int> *removeNode(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    return solve(root, x);
}