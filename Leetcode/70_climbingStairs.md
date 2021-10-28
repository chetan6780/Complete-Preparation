# [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) 🌟

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

### Dynamic Programming

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n ;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
```
