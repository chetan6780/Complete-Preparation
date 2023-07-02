# [25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

### Solution

### Code

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        // Base case
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

        // Reverse list in groups of k
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
