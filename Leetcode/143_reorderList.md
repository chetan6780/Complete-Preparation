# [143. Reorder List](https://leetcode.com/problems/reorder-list/) 🌟🌟

You are given the head of a singly linked-list. The list can be represented as:

`L0 → L1 → … → Ln - 1 → Ln`
Reorder the list to be on the following form:
`L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …`

**You may not modify the values in the list's nodes. Only nodes themselves may be changed**.

### Most intuitive (Using stack)

-   To access the last node fist we can use the stack.
-   Count the length & push node in stack.
-   for half of the length we can just reorder the list.
    -   take the top of the stack.
    -   `nxt` is the next node of the currNode
    -   set `current node's next` to the `top of the stack`.
    -   set the `next of the stack's top` to `nxt`.
    -   finally set `curr` to `nxt`.
-   Set the `last node's next` to `NULL`.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    void reorderList(ListNode* head)
    {
        int listLen = 0;
        stack<ListNode*> stk;

        // Count the length & push node in stack.
        ListNode* p = head;
        while (p) {
            listLen++;
            stk.push(p);
            p = p->next;
        }

        // Reorder the list.
        ListNode* curr = head;
        listLen /= 2;
        while (listLen--) {
            ListNode* stkTop = stk.top();
            stk.pop();
            ListNode* nxt = curr->next;
            curr->next = stkTop;
            stkTop->next = nxt;
            curr = nxt;
        }

        // Set last node to NULL
        curr->next = nullptr;
    }
};
```

### Using Dequeue

-   Push all the nodes into a dequeue and popping alternatively from front and back while reordering the elements.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    void reorderList(ListNode* head)
    {
        deque<ListNode*> dq;
        ListNode *prev = head, *curr = head->next;
        while (curr) {
            dq.push_back(curr);
            prev->next = nullptr;
            prev = curr;
            curr = curr->next;
        }
        curr = head;
        while (!dq.empty()) {
            curr->next = dq.back();
            dq.pop_back();
            curr = curr->next;
            if (!dq.empty()) {
                curr->next = dq.front();
                dq.pop_front();
                curr = curr->next;
            }
        }
    }
};
```
