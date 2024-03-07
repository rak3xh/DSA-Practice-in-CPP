#include <bits/stdc++.h>
using namespace std;
// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

vector<Node *> interweaveNodes(Node *head1, Node *head2)
{
    Node *newHead1 = new Node(-1);
    Node *newHead2 = new Node(-1);
    Node *tail1 = newHead1;
    Node *tail2 = newHead2;
    Node *temp1 = head1;
    Node *temp2 = head2;

    int turn = 0;

    while (temp1 && temp2)
    {
        if (turn == 0)
        {
            if (temp1)
            {
                tail1->next = temp1;
                temp1 = temp1->next;
                tail1 = tail1->next;
                tail1->next = NULL;
            }
            if (temp2)
            {
                tail2->next = temp2;
                temp2 = temp2->next;
                tail2 = tail2->next;
                tail2->next = NULL;
            }
            turn = 1;
        }
        else
        {
            if (temp2)
            {
                tail1->next = temp2;
                temp2 = temp2->next;
                tail1 = tail1->next;
                tail1->next = NULL;
            }
            if (temp1)
            {
                tail2->next = temp1;
                temp1 = temp1->next;
                tail2 = tail2->next;
                tail2->next = NULL;
            }
            turn = 0;
        }
    }

    while (temp1)
    {
        if (turn == 0)
        {
            tail1->next = temp1;
            temp1 = temp1->next;
            tail1 = tail1->next;
            tail1->next = NULL;

            if (temp1)
            {
                tail2->next = temp1;
                temp1 = temp1->next;
                tail2 = tail2->next;
                tail2->next = NULL;
            }
        }
        else
        {
            tail2->next = temp1;
            temp1 = temp1->next;
            tail2 = tail2->next;
            tail2->next = NULL;

            if (temp1)
            {
                tail1->next = temp1;
                temp1 = temp1->next;
                tail1 = tail1->next;
                tail1->next = NULL;
            }
        }
    }

    while (temp2)
    {
        if (turn == 1)
        {
            tail1->next = temp2;
            temp2 = temp2->next;
            tail1 = tail1->next;
            tail1->next = NULL;

            if (temp2)
            {
                tail2->next = temp2;
                temp2 = temp2->next;
                tail2 = tail2->next;
                tail2->next = NULL;
            }
        }
        else
        {
            tail2->next = temp2;
            temp2 = temp2->next;
            tail2 = tail2->next;
            tail2->next = NULL;

            if (temp2)
            {
                tail1->next = temp2;
                temp2 = temp2->next;
                tail1 = tail1->next;
                tail1->next = NULL;
            }
        }
    }

    return {newHead1->next, newHead2->next};
}
int main()
{
}