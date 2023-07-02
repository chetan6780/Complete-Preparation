# [445. Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/)

### Stack Solution

-   store the values in the stack.
-   Maintain carry.
-   Create new node with sum and assign its next to previous linked list.
-   Assign newNode to finalList
-   Return the final linked list.

### Code

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        // store the values in the stack
        stack<int> st1, st2;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        // Create final linked list
        ListNode* finalList = NULL; // it should be NULL otherwise extra node with 0 value will be added in LL
        int carry = 0;

        while (!st1.empty() || !st2.empty() || carry != 0) {
            int s1 = 0, s2 = 0;
            if (!st1.empty()) {
                s1 = st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                s2 = st2.top();
                st2.pop();
            }
            int sum = s1 + s2 + carry;
            carry = sum / 10;
            sum %= 10;
            // Create new node with the sum and point its next to previous linked list
            ListNode* newNode = new ListNode(sum);
            newNode->next = finalList;
            finalList = newNode; // assign newNode to finalList
        }

        return finalList;
    }
};
```
