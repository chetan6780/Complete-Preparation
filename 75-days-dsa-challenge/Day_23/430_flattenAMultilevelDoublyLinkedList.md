# [430. Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)

### Solution

### Code

```cpp
class Solution {
public:
    Node* flatten(Node* head)
    {
        for (Node* headPtr = head; headPtr != NULL; headPtr = headPtr->next) {
            if (headPtr->child) {
                Node* next = headPtr->next;     // store next
                headPtr->next = headPtr->child; // set next
                headPtr->next->prev = headPtr;  // set prev
                headPtr->child = NULL;          // set child
                Node* p = headPtr->next;        // pointer to traverse child's layer

                while (p->next) p = p->next;    // Reach to last node of child's layer

                p->next = next; // set last node of child's layer to stored next node
                if (next) next->prev = p; // connect prev of stored next node to child's layer's last node
            }
        }
        return head;
    }
};
```
