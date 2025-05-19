#include "bits/stdc++.h"
using namespace std;

// BST Node
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

// } Driver Code Ends

/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution
{
public:
    pair<int, int> help(vector<int> &temp, int target)
    {
        int n = temp.size();
        int i = 0;
        int j = n - 1;
        int ans = 0;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (temp[mid] == target)
            {
                if (mid + 1 == n)
                    return {temp[mid - 1], -1};
                else if (mid - 1 < 0)
                    return {-1, temp[mid + 1]};
                return {temp[mid - 1], temp[mid + 1]};
            }
            else if (temp[mid] < target)
            {
                // ans=mid;
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        if (i == n)
            return {temp[j], -1};
        else if (j < 0)
            return {-1, temp[i]};
        return {temp[j], temp[i]};
    }
    void inorder(Node *root, vector<int> &temp)
    {
        if (root == NULL)
            return;
        if (root->left != NULL)
            inorder(root->left, temp);
        temp.push_back(root->data);
        if (root->right != NULL)
            inorder(root->right, temp);
    }
    vector<Node *> findPreSuc(Node *root, int key)
    {
        // code here
        if (root->left == NULL && root->right == NULL)
        {
            Node *pre = new Node(-1);
            Node *suc = new Node(-1);
            return {pre, suc};
        }
        vector<int> temp;
        inorder(root, temp);
        pair<int, int> p = help(temp, key);
        Node *pre = new Node(p.first);
        Node *suc = new Node(p.second);
        return {pre, suc};
    }
};

//{ Driver Code Starts.

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Driver program to test above functions
int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        getline(cin, s);
        int key = stoi(s);

        Solution ob;
        vector<Node *> result = ob.findPreSuc(root, key);
        Node *pre = result[0];
        Node *suc = result[1];

        if (pre != nullptr)
            cout << pre->data << " ";
        else
            cout << -1 << " ";

        if (suc != nullptr)
            cout << suc->data << endl;
        else
            cout << -1 << endl;
        cout << "~" << endl;
    }
    return 0;
}