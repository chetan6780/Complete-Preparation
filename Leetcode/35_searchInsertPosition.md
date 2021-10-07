# [35. Search Insert Position](https://leetcode.com/problems/search-insert-position/)

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

### Prerequsite: Binary Search (704)

### O(log N) Time solution

- Modification of BS.
- l<r
    - if target greater than element at mid.
        - l = mid+1
    - else
        - r = mid  // not mid-1;
- return l

# Code

```cpp
class Solution{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n, mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
```
