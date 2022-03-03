# [413. Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/) 🌟🌟

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

-   For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
    Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

### DP

-   Here array is arithmetic if it consists of at least three elements \*\*\*\*and if the difference between any two consecutive elements is the same.
-   We will be using the sliding window technique, comparing 3 elements at a time and then storing the answer in dp array.
-   Start our loop from 3rd element and compare it with the previous 2 and if there is more than 3 elements with the same difference then we’ll also add that to our dp.
-   Let’s take an example:

```py
	array: [1,2,3,4]
	Here first 3 element:   [1,2,3] is arithmetic -> count=1
	also next 3 element:    [2,3,4] is arithmetic -> count=1
	now all together:     [1,2,3,4] is arithmetic -> count=1
```

-   So while storing 2nd ans in dp, we'll simply add the previous 1 to our current dp.
    `dp[i] = 1 + dp[i-1]`
-   Add the current dp count to our answer variable, count += dp[i];
-   Time complexity: `O(n)`.

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        vector<int> dp(n, 0);
        int ans = 0;

        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
                ans += dp[i];
            }
        }
        return ans;
    }
};
```
