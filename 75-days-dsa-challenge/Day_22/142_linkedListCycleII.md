# [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

### fast ans slow pointer Solution

-   We can use fast and slow pointer method to find the cycle.
-   We move fast by 2 steps and slow by 1 step.
-   When they both are equal, we have found the cycle, else we return null.
-   If cycle found set fast pointer to head again and move both by 1 step.
-   when both of then are equal, we have found the start of the cycle.
-   return the fast/slow pointer.
-   **TC: O(N)**
-   **SC: O(1)**

```cpp
class Solution {
public:
    ListNode* detectCycle(ListNode* head)
    {
        // base case
        if (head == NULL || head->next == NULL) return NULL;

        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
```
