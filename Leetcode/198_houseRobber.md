# [198. House Robber](https://leetcode.com/problems/house-robber/) 🌟🌟

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

### Dynamic Programming

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
