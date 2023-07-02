# [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

### Linear Search

-   Simple implementation of linear search

### Binary search

### Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        // binary search
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < nums[r]) {
                // target is between m and r
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            } else if (nums[m] > nums[r]) {
                // target is between l and m
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else
                r--;
        }
        return -1;
    }
};
```
