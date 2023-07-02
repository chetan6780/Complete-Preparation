# [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)

### Brute force

-   We check for every node from the smaller LL, if there exists **SAME NODE**(not just same value) in the bigger LL, then we return that node, else we return null.
-   **TC: O(M\*N)** where M is the length of smaller LL and N is the length of bigger LL.

### Hashing improvement

-   We take a hashmap.
-   While traversing first LL we put the **node(not node value)** in the hashmap.
-   While traversing the second LL we check if the node is present in the hashmap or not.
-   If present then we return that node, else we return null
-   **TC: O(M+N)**- Assuming hashing works in **O(1)**
-   **SC: O(M+N)**- (Hashmap)

### Constant space O(N) Time optimization

-   We calculate the length of both LLs.
-   We move the pointers of the larger LL to the difference of the length of the two LLs.
-   We traverse both LLs simultaneously.
-   If we find the same node, then we return that node, else return null.
-   **TC: O(N)**- N is the length of the longer LL
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (headA == NULL || headB == NULL) return NULL; // Remember this case also, you forgot

        int len1 = 0, len2 = 0;
        ListNode *ptr1 = headA, *ptr2 = headB;
        while (ptr1 != NULL) {
            len1++;
            ptr1 = ptr1->next;
        }
        while (ptr2 != NULL) {
            len2++;
            ptr2 = ptr2->next;
        }
        ptr1 = headA, ptr2 = headB;
        if (len1 > len2) {
            int temp = len1 - len2;
            while (temp--) {
                ptr1 = ptr1->next;
            }
        } else {
            int temp = len2 - len1;
            while (temp--) {
                ptr2 = ptr2->next;
            }
        }

        while (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1 == ptr2) {
                return ptr1;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }
};
```

### Same complexity another method.

-   we take two pointers, one from headA and one from headB.
-   move both of then simultaneously.
-   if any of the pointers reach to Null, then set that pointer to the start of the **other LL**.
-   Then if insertion point present both the pointers point to the same node, then return that node.
-   if both pointers reach to Null, then return NULL.
-   The complexity is same but the code is small.

```cpp
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (headA == NULL || headB == NULL) return NULL;

        ListNode *ptr1 = headA, *ptr2 = headB;

        while (ptr1 != ptr2) {
            ptr1 = (ptr1 == NULL) ? headB : ptr1->next;
            ptr2 = (ptr2 == NULL) ? headA : ptr2->next;
        }
        return ptr1;
    }
};
```
