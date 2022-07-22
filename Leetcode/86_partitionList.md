# [86. Partition List](https://leetcode.com/problems/partition-list/) 🌟🌟

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

**Note:** We are not supposed to arrange linked list such that all nodes less than x are on one side and all nodes greater than or equal to x are on the other side.**We have to maintain original order of the nodes.**

### Solution

-   We create 2 linked lists, one for nodes less than x and one for nodes greater than or equal to x.
-   Also we need two pointer to point to the head of each list.
-   Now traverse the linked list and compare the value of each node with x.
    -   if the value is less than x, add it in less linked list, move pointer off less.
    -   else add it in greater linked list, move pointer off greater linked list.
-   finally join both linked list and set last node of greater linked list to null.
-   Return `less->next` which is pointing to the head of the resultant linked list.

```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* less = new ListNode(0); // ll containing all less than x valued nodes
        ListNode* more = new ListNode(0); // ll containing all more than or equal to x valued nodes in original order
        ListNode* lessHead = less; // head of less ll
        ListNode* moreHead = more; // head of more ll

        while (head) {
            if (head->val < x) {
                // add to less ll
                lessHead->next = head;
                lessHead = lessHead->next;
            } else {
                // add to more ll
                moreHead->next = head;
                moreHead = moreHead->next;
            }
            head = head->next;
        }
        // join less and more linked lists
        lessHead->next = more->next;
        // set head of more ll to null. i.e.last node of more ll is null now.
        moreHead->next = nullptr;
        return less->next;
    }
};
```
