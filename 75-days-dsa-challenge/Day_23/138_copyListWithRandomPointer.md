# [138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)

### Brute force

-   Take `hashmap<originalNode,copyNode>`
-   Traverse the linked list and create deep copy of the current node and push both in the hashmap.
-   Now traverse the linked list again and point deep copied node to the other deep copy nodes as present in original node.
-   **TC: O(N)**
-   **SC: O(N)**

### Optimized

-   3 Step algorithm explained in code.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        Node* iter = head;
        Node* front = head;

        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while (iter != NULL) {
            front = iter->next;

            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
        }

        // Second round: assign random pointers for the copy nodes.
        iter = head;
        while (iter != NULL) {
            if (iter->random != NULL) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        // Third round: restore the original list, and extract the copy list.
        iter = head;
        Node* pseudoHead = new Node(0);
        Node* copy = pseudoHead;

        while (iter != NULL) {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;

            copy = copy->next;
            iter = front;
        }

        return pseudoHead->next;
    }
};
```
