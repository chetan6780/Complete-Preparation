# [23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

### Vector + sorting

-   Store all the values of node in the vector.
-   Sort the vector.
-   create a new list and add the values to the list.
-   return the head of the list.
-   **TC: O(N log N)**, Where N = total number of nodes in the list.
-   **SC: O(N)**, Where N = total number of nodes in the list.

### Code

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        vector<int> ans;
        for (auto x : lists) {
            while (x) {
                ans.push_back(x->val);
                x = x->next;
            }
        }
        sort(ans.begin(), ans.end());
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        for (auto x : ans) {
            temp->next = new ListNode(x);
            temp = temp->next;
        }
        return head->next;
    }
};
```

### Priority Queue

-   The same idea as the above solution can be implimented using priority queue.
-   **TC: O(N log N)**, Where N = total number of nodes in the list.
-   **SC: O(N)**, Where N = total number of nodes in the list.

### Code

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        for (auto& list : lists) {
            while (list) {
                pq.push(list->val);
                list = list->next;
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (!pq.empty()) {
            int val = pq.top();
            pq.pop();
            ListNode* node = new ListNode(val);
            if (!head) {
                head = node;
            }
            if (tail) {
                tail->next = node;
            }
            tail = node;
        }
        return head;
    }
};
```

### Divide and conquer

-   This problem can be efficiently solved using divide and conquer.
-   We divide the list in 2 halves and merge the two halves recursively.

### Code

```cpp

class Solution {
private:
    // mergeTwoLists function
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        // if l1 is null, return l2
        if(l1 == NULL) return l2;
        // if l2 is null, return l1
        if(l2 == NULL) return l1;
        // if l1 and l2 are both null, return null
        if(l1 == NULL && l2 == NULL) return NULL;

        // if l1 and l2 are both not null, compare l1 and l2
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // using divide and conquer technique
        // divide
        int n = lists.size();
        if (n == 0)
            return NULL;
        if (n == 1)
            return lists[0];
        if (n == 2)
            return mergeTwoLists(lists[0], lists[1]);

        int mid = n / 2;
        vector<ListNode*> left(mid);
        vector<ListNode*> right(n - mid);

        for (int i = 0; i < mid; i++)
            left[i] = lists[i];
        for (int i = mid; i < n; i++)
            right[i - mid] = lists[i];

        // conquer
        ListNode* l1 = mergeKLists(left);
        ListNode* l2 = mergeKLists(right);

        return mergeTwoLists(l1, l2);
    }
};
```
