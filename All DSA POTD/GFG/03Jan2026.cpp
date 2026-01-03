#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    Node *flatten(Node *root)
    {
        // code here
        if (root->next == NULL)
        {
            return root;
        }

        vector<Node *> v;
        Node *temp = root;
        Node *tnext = NULL;

        while (temp)
        {
            tnext = temp->next;
            temp->next = NULL;
            v.push_back(temp);
            temp = tnext;
        }

        Node *pre1 = NULL;
        Node *pre2 = NULL;
        Node *curr1 = NULL;
        Node *curr2 = NULL;

        for (int i = 1; i < v.size(); i++)
        {

            curr1 = v[0];
            curr2 = v[i];

            while (curr1 && curr2)
            {

                if (curr1->data <= curr2->data)
                {
                    pre1 = curr1;
                    curr1 = curr1->bottom;
                }
                else
                {
                    pre2 = curr2;
                    curr2 = curr2->bottom;

                    pre2->bottom = curr1;
                    pre1->bottom = pre2;

                    pre1 = pre1->bottom;
                    pre2 = NULL;
                }
            }

            if (curr1 == NULL)
            {
                pre1->bottom = curr2;
            }
        }

        return v[0];
    }
};