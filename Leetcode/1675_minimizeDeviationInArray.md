# [1675. Minimize Deviation in Array](https://leetcode.com/problems/minimize-deviation-in-array/) 🌟🌟🌟

You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

-   If the element is **even, divide** it by 2.
    -   For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
-   If the element is **odd, multiply** it by 2.
    -   For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].

The **deviation** of the array is the **maximum difference** between any two elements in the array.

Return the **minimum deviation** the array can have after performing some number of operations.

### Priority Queue (AC)

### Code

```cpp
class Solution {
public:
    int minimumDeviation(vector<int>& nums)
    {
        int n = nums.size();
        int mx = INT_MIN, mn = INT_MAX;

        // Increase the odd numbers to its maximum value which is num*2 & track min,max num.
        for (int i = 0; i < n; ++i) {
            if ((nums[i] % 2) & 1)
                nums[i] *= 2;
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        int minDev = mx - mn;

        priority_queue<int> pq;
        // Inserting nums Priority queue (Max Heap)
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }

        while (((pq.top()) & 1) == 0) {
            int topNum = pq.top();
            pq.pop(); // popped the top element

            minDev = min(minDev, topNum - mn);
            topNum /= 2;
            mn = min(mn, topNum); // updating min
            pq.push(topNum); // pushing again the top as we have to minimize the max
        }

        minDev = min(minDev, pq.top() - mn);

        return minDev;
    }
};
```

### Set

### Code

```cpp
// <!-- TODO: Code here -->
```

### Must Read

-   [✅ C++ || Easy || 2 Approaches || Priority Queue || Set](https://leetcode.com/problems/minimize-deviation-in-array/discuss/1781709/C%2B%2B-oror-Easy-oror-2-Approaches-oror-Priority-Queue-oror-Set)
