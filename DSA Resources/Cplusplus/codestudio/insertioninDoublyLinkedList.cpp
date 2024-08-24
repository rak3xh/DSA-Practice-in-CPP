#include <bits/stdc++.h>

class Node
{

public:
    int data;

    Node *next;

    Node *prev;

    Node(int val)
    {

        this->data = val;

        next = NULL;

        prev = NULL;
    }

    ~Node()
    {

        if (next != NULL || prev != NULL)
        {

            delete next;
        }
    }
};

Node *insert(int k, int val, Node *head)
{

    // Write Your Code Here.

    Node *newnode = new Node(val);

    if (head == nullptr)
        return newnode;

    if (k == 0)
    {

        // inserting at head

        newnode->next = head;

        head->prev = newnode;

        return newnode;
    }

    int counter = 0;

    Node *temp = head;

    Node *prv = nullptr;

    while (temp != nullptr)
    {

        if (counter == k)
        {

            newnode->prev = prv;

            newnode->next = temp;

            prv->next = newnode;

            temp->prev = newnode;

            break;
        }

        counter++;

        prv = temp;

        temp = temp->next;
    }

    if (temp == nullptr)
    {

        prv->next = newnode;

        newnode->prev = prv;
    }

    return head;
}
