# [198. House Robber](https://leetcode.com/problems/house-robber/) 🌟🌟

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

### Dynamic Programming

-   We can rob current house or not rob the current house.
-   If we rob the current house then amount will be `current house amount + i-2th house amount`.
-   else the amount will be `i-1th house amount`.
-   we can choose whichever is maximum

### Code

```cpp
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};
```

### Reduced space complexity DP.

-   There are only two choices for the robber, either he rob the i the house or he don't.
-   So the maximum he can rob is `rob(i) = max(rob(i-1), rob(i-2) + nums[i])`
-   in the below code we store `rob(i-1)` in `prev1` and `rob(i-2)` in prev2.

### Code

```cpp
class Solution {
public:
    int rob(vector<int>& nums){
        if (nums.size() == 0) return 0;

        int prev1 = 0, prev2 = 0;
        for (auto& x : nums) {
            int temp = prev1;
            prev1 = max(prev1, x + prev2);
            prev2 = temp;
        }
        return prev1;
    }
};
```

### MUST READ:

-   [From good to great. How to approach most of DP problems.](https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.)
