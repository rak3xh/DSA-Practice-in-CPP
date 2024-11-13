#include <iostream>

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

vector<int> take()
{
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
        arr.push_back(number);
    }
    return arr;
}

Node *inputList(int size, vector<int> v)
{
    if (size == 0)
        return NULL;

    int val = v[0];

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        val = v[i + 1];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    // Function to find intersection point in Y shaped Linked Lists.
    int lengthLL(Node *head)
    {
        Node *mover = head;
        int length = 0;
        while (mover)
        {
            length++;
            mover = mover->next;
        }
        return length;
    }
    int intersectPoint(Node *head1, Node *head2)
    {
        // Your Code Here
        int l1 = lengthLL(head1);
        int l2 = lengthLL(head2);
        if (l1 > l2)
        {
            Node *curr1 = head1;
            Node *curr2 = head2;
            int diff = 0;
            while (diff != l1 - l2)
            {
                curr1 = curr1->next;
                diff++;
            }
            while (curr1 && curr2)
            {
                if (curr1 == curr2)
                {
                    return curr1->data;
                }
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            return -1;
        }
        else
        {
            Node *curr1 = head1;
            Node *curr2 = head2;
            int diff = 0;
            while (diff != l2 - l1)
            {
                curr2 = curr2->next;
                diff++;
            }
            while (curr1 && curr2)
            {
                if (curr1 == curr2)
                {
                    return curr1->data;
                }
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            return -1;
        }
        return -1;
    }
};

//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    srand(time(0));
    int T, n1, n2, n3;

    cin >> T;
    cin.ignore();
    while (T--)
    {

        vector<int> v1 = take();
        vector<int> v2 = take();
        vector<int> v3 = take();
        int n1 = v1.size(), n2 = v2.size(), n3 = v3.size();

        Node *head1 = NULL;
        Node *head2 = NULL;
        Node *common = NULL;

        head1 = inputList(n1, v1);
        head2 = inputList(n2, v2);
        common = inputList(n3, v3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
        cout << "~" << endl;
    }
    return 0;
}