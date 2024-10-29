#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
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

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node *&head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// } Driver Code Ends

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution
{
private:
    struct Node *partition(struct Node *head, struct Node *tail)
    {
        // Select the first node as the Pivot node
        Node *pivot = head;

        // 'pre' and 'curr' are used to shift all smaller nodes data to leftside of the pivot node
        Node *pre = head;
        Node *curr = head;

        // Traverse the list until reach to the node after the tail
        while (curr != tail->next)
        {
            // if current node's data is less than the pivot's data
            if (curr->data < pivot->data)
            {
                // Swap the data Between "curr" ans "pre->next"
                swap(curr->data, pre->next->data);
                // Move "pre" to the next node
                pre = pre->next;
            }
            // Mode "curr" to the next node
            curr = curr->next;
        }
        // Swap the pivot's data with pre data
        swap(pivot->data, pre->data);
        // Return "pre" as the new pivot
        return pre;
    }
    void quickSortHelper(struct Node *head, struct Node *tail)
    {
        // Base Case: if the list is empty or consists of a singlenode
        if (!head || head == tail)
            return;

        // Call partition to find the pivot node
        Node *pivot = partition(head, tail);

        // Recursive call for the left part of the list(before the pivot)
        quickSortHelper(head, pivot);

        // Recursive call for the right part of the list(after the pivot)
        quickSortHelper(pivot->next, tail);
    }

public:
    struct Node *quickSort(struct Node *head)
    {
        // code here
        // Edge case : if the list is empty or consists of a single node
        if (!head || !head->next)
            return head;

        // Find the tail node (last node of the list)
        Node *temp = head;
        while (temp->next)
            temp = temp->next;

        // Tail points to the last node
        Node *tail = temp;

        // Call quickSortHelper to sort the list
        quickSortHelper(head, tail);

        // Return the head of the sorted list
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--)
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

        if (arr.empty())
        {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i)
        {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}