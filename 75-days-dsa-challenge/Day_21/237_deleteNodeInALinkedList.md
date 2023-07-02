# [237. Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)

### Solution 😂🤣🤣

-   We just need to copy the next node's value to the current node and then delete the next node.

### Code

```cpp
class Solution {
public:
    void deleteNode(ListNode* node){
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```

### 📌 MUST READ:

> let's analyze why this problem **isn't a good interview question**.

```
The whole point of asking any candidates a linked list problem is to test if the candidates think about edge cases, including:

1. Dereferencing Null Pointer, usually targeting tail pointer
2. When given Head is None
3. When there are duplications in the list
```

> This question specifically mentioned all the above edge cases and extracted them out for you Someone who can solve this problem might not even think of all the edge cases, which can backfire on them in real interview settings
