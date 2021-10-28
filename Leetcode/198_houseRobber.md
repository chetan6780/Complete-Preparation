# [198. House Robber](https://leetcode.com/problems/house-robber/) 🌟🌟

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

### Dynamic Programming

### Code

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;

        int prev1=0,prev2=0;
        for(auto &x:nums){
            int temp = prev1;
            prev1 = max(prev1,x+prev2);
            prev2=temp;
        }
        return prev1;
    }
};
```

### MUST READ:

- [From good to great. How to approach most of DP problems.](https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.)
