# [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) 🌟

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

### O(N) Time and O(1) Space

- if value of current node is equal to the value of the next node, delete the next node
- else traverse next node,

### Code

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        ListNode *curr=head;

        while(curr->next!=NULL){
            if(curr->val==curr->next->val){
                curr->next=curr->next->next;
            }else{
                curr=curr->next;
            }
        }
        return head;
    }
};
```
