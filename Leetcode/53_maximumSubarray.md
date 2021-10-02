# [53. Maximum Subarray](https://leetcode.com/problems/contains-duplicate/) 🌟

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

### O(N) time constant space(DP)

- We maintain a maximum sum and current sum(if element itself is max)
- for each i=(0,n)
  - add current element to current sum
  - mx = max(current sum , mx);
  - current sum will be max(0,current sum);
- finally we return mx

### Code

```cpp
class Solution{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int mx = nums[0];
        int sm = 0;
        for (int i = 0; i < n; i++)
        {
            sm += nums[i];
            mx = max(sm, mx);
            sm = max(sm, 0);
        }
        return mx;
    }
};
```
