# [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) 🌟🌟

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

### Brute Force

-   We want to find maximum product subarray, so we can just create all subarrays and find maximum product subarray among them.
-   **TC: O(N^2)**
-   **SC: O(1)**

### Kaden's algorithm

<!-- TODO: Explanation -->

-   **TC: O(n)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int prefix = 0, suffix = 0, max_so_far = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            prefix = (prefix ? prefix : 1) * nums[i];
            suffix = (suffix ? suffix : 1) * nums[n-1-i];
            max_so_far = max({ max_so_far, prefix, suffix });
        }
        return max_so_far;
    }
};
```
