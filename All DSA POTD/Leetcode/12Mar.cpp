#include <unordered_map>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        // Create a dummy head node to handle edge cases seamlessly
        ListNode *dummyHead = new ListNode(0, head);
        std::unordered_map<int, ListNode *> lastSeenPrefixSum;
        ListNode *current = dummyHead;
        int prefixSum = 0;

        // First pass to record the last occurrence of each prefix sum
        while (current)
        {
            prefixSum += current->val;
            lastSeenPrefixSum[prefixSum] = current;
            current = current->next;
        }

        // Reset the prefix sum and re-iterate from the dummy head
        prefixSum = 0;
        current = dummyHead;

        // Second pass to connect nodes bypassing the zero-sum sublists
        while (current)
        {
            prefixSum += current->val;
            // Link the current node to the node following the last occurrence of the same prefix sum
            // This effectively removes the zero-sum sublists
            current->next = lastSeenPrefixSum[prefixSum]->next;
            current = current->next;
        }

        // Return the next element of the dummy head which would be the new list head
        return dummyHead->next;
    }
};
