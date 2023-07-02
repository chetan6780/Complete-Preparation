# [34. Find First and Last Position of Element in Sorted Array](https://docs.google.com/spreadsheets/d/1SBx6ifpBn3TVCQWSzK9ka26glyNTyS-fqn6bfOVaXFE/edit#gid=0)

### Linear search

-   find first occurrence from start and last occurrence from end.

### binary search

-   Just small modification in normal binary search.
-   To find the first occurrence, if we found target store it in ans and move right pointer to mid - 1.
-   To find the last occurrence, if we found the target store it in ans and move left pointer to mid + 1.

### code

```cpp
class Solution {
private:
    int firstOccurrence(vector<int>& nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                r = mid - 1;
                ans = mid;
            } else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
    int lastOccurrence(vector<int>& nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                l = mid + 1;
                ans = mid;
            } else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int first = firstOccurrence(nums, target);
        int last = lastOccurrence(nums, target);
        return vector<int> { first, last };
    }
};
```
