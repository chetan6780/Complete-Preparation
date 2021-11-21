# [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) 🌟🌟🌟

Given n non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

### Brute force

-   For every index find the max water that can be trapped.
-   This can be done with the formula `min(maxLeft(i),maxRight(i))-a[i]`
-   **TC: O(N^2)**, 2nd loop for finding left and right max.
-   **SC: O(1)**

### PrefixSum Optimized

-   We can pre-compute left max in an array and right max from back into the another array, so the 2 loop is not necessary.
-   **TC: O(N)**
-   **SC: O(2\*N)-->O(N)**

### 2-pointer

-   We can find left max and right max with 2 pointer approach.
-   Explained in code.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int res = 0;
        int maxleft = 0, maxright = 0;

        while (left <= right) {
            if (height[left] <= height[right]) { // update max left
                if (height[left] >= maxleft) maxleft = height[left];
                else res += maxleft - height[left];
                left++;
            } else { // update max right
                if (height[right] >= maxright) maxright = height[right];
                else res += maxright - height[right];
                right--;
            }
        }
        return res;
    }
};
```
