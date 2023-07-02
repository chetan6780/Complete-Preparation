# [https://leetcode.com/problems/kth-largest-element-in-an-array/](https://leetcode.com/problems/kth-largest-element-in-an-array/)

### Sorting

-   sort the array and return `n-k`th element.

### Priority Queue

-   push all elements into a priority queue and pop `k-1` elements from it.
-   the top of the priority queue is the k-th largest element.

### Code

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto x:nums){
            pq.push(x);
        }
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};
```
