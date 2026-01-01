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
    Node *intersectPoint(Node *head1, Node *head2)
    {
        //  Code Here
        // If either linked list is empty, intersection is not possible
        if (head1 == NULL || head2 == NULL)
            return NULL;

        // Initialize two pointers for both linked lists
        Node *x1 = head1;
        Node *x2 = head2;

        // Traverse both lists until the pointers meet
        // They will either meet at the intersection node or at NULL
        while (x1 != x2)
        {

            // If x1 reaches the end of list1, redirect it to head2
            // Otherwise move to the next node
            x1 = (x1 == nullptr) ? head2 : x1->next;

            // If x2 reaches the end of list2, redirect it to head1
            // Otherwise move to the next node
            x2 = (x2 == nullptr) ? head1 : x2->next;
        }

        // x1 and x2 now point to the intersection node
        // or NULL if there is no intersection
        return x2;
    }
};