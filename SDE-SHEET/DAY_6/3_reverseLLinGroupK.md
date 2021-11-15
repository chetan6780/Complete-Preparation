# [25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) 🌟🌟🌟

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

### Algorithm

<!-- TODO: Add explanation, redo this question -->

-   Watch [striver's video'](https://www.youtube.com/watch?v=Of0HPkk3JgI) for better understanding.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (head == NULL || k == 1)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *curr = dummy, *next = dummy, *pre = dummy;
        int count = 0;

        while (curr->next != NULL) {
            curr = curr->next;
            count++;
        }

        while (count >= k) {
            curr = pre->next;
            next = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = curr->next;
            }
            pre = curr;
            count -= k;
        }
        return dummy->next;
    }
};
```
