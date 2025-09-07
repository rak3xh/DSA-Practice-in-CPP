#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *mergeKLists(vector<Node *> &arr)
    {
        // code here
        priority_queue<pair<int, pair<int, Node *>>, vector<pair<int, pair<int, Node *>>>, greater<pair<int, pair<int, Node *>>>> pq;

        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({arr[i]->data, {i, arr[i]}});
        }
        Node *ans = NULL;
        Node *temp = NULL;
        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int val = p.first;
            int index = p.second.first;
            Node *node = p.second.second;
            if (ans == NULL)
            {
                ans = node;
                temp = node;

                node = node->next;
                temp->next = NULL;
                if (node != NULL)
                {
                    arr[index] = node;
                    pq.push({node->data, {index, node}});
                }
            }
            else
            {
                temp->next = node;
                temp = temp->next;

                node = node->next;
                temp->next = NULL;
                if (node != NULL)
                {
                    arr[index] = node;
                    pq.push({node->data, {index, node}});
                }
            }
        }
        return ans;
    }
};