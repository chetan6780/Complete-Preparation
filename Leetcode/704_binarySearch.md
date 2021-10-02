# [704. Binary Search](https://leetcode.com/problems/binary-search/) 🌟

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

### O(log N) Time algorithm

- **NOTE:** _Array must be sorted.if not then sort array first._
- Point two variables l and r to the first and last position of array.
- while(l<=r)
  - if middle element is target then return middle index
  - if middle element is greater than target then r = middle - 1
  - if middle element is less than target then l = middle + 1
- if we cant find element in array, return -1.

### l+(r-l)/2 is more efficient than (l+r)/2 for larger values of l and r.mathematically both are same.

### Code

```cpp
class Solution{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
```
