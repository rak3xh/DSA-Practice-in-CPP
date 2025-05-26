#include <bits/stdc++.h>
using namespace std;
// structure for a node
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
    Node *sortedInsert(Node *head, int data)
    {
        // code here
        if (head->data > data)
        {
            Node *curr = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            Node *newnode = new Node(data);
            curr->next = newnode;
            newnode->next = head;
            return newnode;
        }
        Node *curr = head;
        Node *prev = head;
        while (curr->data <= data)
        {
            prev = curr;
            curr = curr->next;
            if (curr == head)
            {
                break;
            }
        }

        Node *newnode = new Node(data);
        prev->next = newnode;
        newnode->next = curr;
        return head;
    }
};