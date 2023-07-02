# [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

### O(N) Time and O(1) Space Complexity

-   Get the length of the linked list.
-   if n = length then return head->next
-   n = length - n
-   go to n-1th node then set its next to its next->next.
-   delete the space of removed node, else it will cause memory leak.
-   return head

### Code

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        if (n == len) return head->next;

        n = len - n;
        temp = head;
        while (--n) {
            temp = temp->next;
        }
        ListNode* deleteNode=temp->next;
        temp->next = temp->next->next;
        delete deleteNode;
        return head;
    }
};
```

### O(N) Time and O(1) Space Complexity, two pointers

-   We take 2 pointers, fast and slow. (here both move equally i.e. 1 node at a time)
-   move fast pointer n times.
-   if fast is null return head->next
-   now move slow and fast pointers together until fast->next != NULL.
-   slow->next = slow->next->next
-   Delete deleted node.
-   **NOTE:** This method have same complexity as above method.

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head,*slow = head;
        while(n--) fast = fast->next;
        if(!fast) return head->next;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* deleteNode=slow->next;
        slow->next = slow->next->next;
        delete deleteNode;
        return head;
    }
};
```
