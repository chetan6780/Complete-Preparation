# [1413. Minimum Value to Get Positive Step by Step Sum](https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/) 🌟

Given an array of integers nums, you start with an initial positive value startValue.

In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

Return the minimum positive value of startValue such that the step by step sum is never less than 1.

### PrefixSum O(N) Time

-   We calculate the running sum (prefix sum) of the array.
-   Every time we find minimum sum we got until now.
-   return abs(minimum sum) + 1.

```cpp
class Solution {
public:
    int minStartValue(vector<int>& nums){
        int prefSum = 0, minVal = 0;
        for (int x : nums) {
            prefSum += x;
            minVal = min(minVal, prefSum);
        }
        return abs(minVal) + 1;
    }
};
```
