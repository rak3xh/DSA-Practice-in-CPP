#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int sum = 0;
    void transformTree(Node *root)
    {
        // code here
        if (!root)
        {
            return;
        }
        transformTree(root->right);
        int rootData = root->data;
        root->data = sum;
        sum += rootData;
        transformTree(root->left);
    }
};