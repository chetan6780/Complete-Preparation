# [53. Maximum Subarray](https://leetcode.com/problems/contains-duplicate/) 🌟

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

### O(N^3) Solution

- Brute force
- We will check for all the subarray and find the maximum sum.
- ```
    for(i=0,n)
        for (j=i,n)
            for(k=i,j)
                check for max subarray sum
  ```

### O(N^2) Solution

- Since we are running 3rd loop from i to j we can do this by using only 2 loops.
- in the beginning of 2nd loop set sum = 0 and in 2nd loop keep adding elements to sum and update the max sum.
- ```
    for(i=0,n)
        sum=0;
        for (j=i,n)
            sum+= arr[i];
            maxS=max(maxS,sum);
  ```

### O(N) time constant space(DP)/Kadane's algorithm

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
    int maxSubArray(vector<int> &nums) // Kadane's algorithm
    {
        int n = nums.size();
        int mx = nums[0];
        int sm = 0;
        for (int i = 0; i < n; i++)
        {
            sm += nums[i];
            mx = max(sm, mx);
            if (sm < 0)
                sm = 0;
        }
        return mx;
    }
};
```
