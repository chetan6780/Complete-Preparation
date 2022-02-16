# [24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) 🌟🌟

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

-   **ALL THE SOLUTIONS ARE SELF EXPLANATORY**

### By swapping values

-   **Recursive solution**

```cpp
class Solution {
private:
    ListNode* swapPairsRec(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        swap(head->val,head->next->val);
        swapPairsRec(head->next->next);
        return head;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return swapPairsRec(head);
    }
};
```

-   **Iterative solution**

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp = head;
        while(head!=NULL && head->next!=NULL){
            swap(head->val,head->next->val);
            head = head->next->next;
        }
        return temp;
    }
};
```

### By swapping Nodes

-   **Recursive solution**

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }

        ListNode* temp;
        temp = head->next;

        head->next = swapPairs(head->next->next); // change links
        temp->next = head;

        return temp; // now after changing links, temp act as our head
    }
};
```

-   **Iterative solution**

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next)
            return head;

        ListNode* temp = new ListNode();
        ListNode *prev = temp, *curr = head;

        while (curr && curr->next) {
            // swap
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;

            // update the pointers
            prev = curr;
            curr = curr->next;
        }

        return temp->next;
    }
};
```
