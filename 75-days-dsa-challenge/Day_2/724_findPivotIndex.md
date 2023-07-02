# [724. Find Pivot Index](https://leetcode.com/problems/find-pivot-index/) (Easy)

### Prefix sum

-   If sum of left and right part of index i is same then we can return i as pivot.
    -   left sum is sum till i'th number.
    -   right sum is total `sum - left sum - i'th number`.
-   If we didn't find pivot then we return -1.

### Code

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
```
