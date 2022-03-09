# [82. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) 🌟🌟

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

### Solution

-   Explained in code.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        // Create a temporary node
        ListNode* newNode = new ListNode(0);
        ListNode* pre = newNode;
        while (head != NULL) {
            // If the next node is not null and the value is same as current node
            if (head->next != NULL && head->val == head->next->val) {
                // Skip duplicates
                while (head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
            } else {
                // If the next node is not null and the value is different from current node
                // Add the node to the list
                pre->next = head;
                pre = pre->next;
            }
            head = head->next;
        }
        // set last node to null
        pre->next = NULL;

        return newNode->next;
    }
};
```
