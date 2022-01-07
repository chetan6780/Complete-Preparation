# [382. Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/) 🌟🌟

Given a singly linked list, return a random node's value from the linked list. Each node must have the **same probability** of being chosen.

Implement the Solution class:

-   `Solution(ListNode* head)` Initializes the object with the integer array nums.
-   `int getRandom()` Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.

### Naive Solution

-   We can convert linked list into an array and return a random element from the array.
-   **TC: O(N)**
-   **SC: O(N)**

### Reservoir Sampling Solution
- In order to do random sampling over a population of **unknown size** with constant space, the answer is reservoir sampling.
> The reservoir sampling algorithm is intended to sample k elements from an population of unknown size. In our case, the k happens to be one.

### Code

```cpp
class Solution {
private:
    ListNode* root;

public:
    Solution(ListNode* head){
        this->root = head;
    }

    int getRandom()
    {
        ListNode* curr = root;
        int ans = 0, x = 1;
        while (curr) {
            if (rand() % x == 0) ans = curr->val;
            x++;
            curr = curr->next;
        }
        return ans;
    }
};
```
- `rand()` output has range of `[0,RAND_MAX)`
so the `i` variable here is kinda like `curr_depth+1` so so at each step its `[0,depth+1)`