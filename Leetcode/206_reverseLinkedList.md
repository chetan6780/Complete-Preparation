# [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) 🌟

Given the head of a singly linked list, reverse the list, and return the reversed list.


- Initialize three pointers prev as NULL, curr as head and next as NULL.
- Iterate through the linked list. In loop, do following.
  // Before changing next of current, store next node
  next = curr->next
  // Now change next of current This is where actual reversing happens
  curr->next = prev
  // Move prev and curr one step forward
  prev = curr
  curr = next

### Code
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL,*next=NULL,*curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
```

### Code
```cpp

```