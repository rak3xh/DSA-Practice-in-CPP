#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

void append(struct Node **head_ref, struct Node **tail_ref, int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;

    *tail_ref = new_node;
}

// } Driver Code Ends
/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution
{
public:
    Node *deleteK(Node *head, int K)
    {
        // Your code here
        if (K == 1)
            return NULL;
        Node *prev = NULL;
        Node *cur = head;
        Node *nxt = head->next;
        int cnt = 1;
        while (cur != NULL)
        {
            if (cnt % K == 0)
            {
                prev->next = nxt;
                cnt++;
                cur = nxt;
                if (cur != NULL)
                    nxt = cur->next;
                continue;
            }
            prev = cur;
            cur = nxt;
            if (nxt != NULL)
                nxt = nxt->next;
            cnt++;
        }
        return head;
    }
};

//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T, i, n, l;
    cin >> T;
    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }
        int K;
        cin >> K;
        Solution obj;
        Node *res = obj.deleteK(head, K);
        Node *temp = res;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return 0;
}