# [148. Sort List](https://leetcode.com/problems/sort-list/) 🌟🌟

Given the head of a linked list, return the list after sorting it in ascending order.

### Intuitive Approach

-   Store all the values of the nodes in the array.
-   Sort the array.
-   Create new Linked List from the sorted array.

### Code

```cpp
class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        vector<int> nodeVals;
        ListNode* temp = head;
        while (temp) {
            nodeVals.push_back(temp->val);
            temp = temp->next;
        }
        sort(nodeVals.begin(), nodeVals.end());
        ListNode* newHead = new ListNode(-1);
        temp = newHead;
        for (auto x : nodeVals) {
            ListNode* newNode = new ListNode(x);
            temp->next = newNode;
            temp = newNode;
        }
        return newHead->next;
    }
};
```

### merge sort

-   Same like array merge sort.

### Code

```cpp
class Solution {
private:
    ListNode* getMid(ListNode* head)
    {
        ListNode* midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode tempHead(0);
        ListNode* ptr = &tempHead;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        if (l1)
            ptr->next = l1;
        else
            ptr->next = l2;

        return tempHead.next;
    }

public:
    ListNode*
    sortList(ListNode* head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
};
```
