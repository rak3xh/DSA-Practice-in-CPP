#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
public:
    int ans = -1;
    void Solve(Node *root, int k)
    {
        if (root == NULL)
            return;
        if (root->data <= k)
        {
            ans = root->data;
            Solve(root->right, k);
        }
        else
            Solve(root->left, k);
    }
    int findMaxFork(Node *root, int k)
    {
        // code here
        Solve(root, k);
        return ans;
    }
};