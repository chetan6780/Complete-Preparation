# [740. Delete and Earn](https://leetcode.com/problems/delete-and-earn/) 🌟🌟

You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

-   similar problem as House robber

### House robber - DP

-   If we observe here this problem is very similar to House robber problem.
-   Since the range of values is upto 10^4, We can calculate how many points we can get from ith number.
-   We traverse through the array and store points we can get from ith number.
-   We can maximize the points with the same approach as the House robber problem.

### Code

```cpp
class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        vector<int> sums(10001, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sums[nums[i]] += nums[i];
        }

        // house robber code
        vector<int> dp(10001, 0);
        dp[0] = sums[0];
        dp[1] = max(sums[0], sums[1]);
        for (int i = 2; i < 10001; i++) {
            dp[i] = max(sums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[10000];
    }
};
```

### Space optimization DP

-   Since we are using only last two values we can optimize the space complexity to O(1).

### Code

```cpp
class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        vector<int> sums(10001, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sums[nums[i]] += nums[i];
        }

        // house rober code
        int first = sums[0];
        int second = max(sums[0], sums[1]);
        for (int i = 2; i < 10001; i++) {
            int curr = max(sums[i] + first, second);
            first = second;
            second = curr;
        }
        return second;
    }
};
```
