# [485. Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/) 🌟

Given a binary array nums, return the maximum number of consecutive 1's in the array.

### Simple iterative solution

### Code

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int n = nums.size(), mx = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                mx = max(mx, cnt);
                cnt = 0;
            } else
                cnt++;
        }
        mx = max(mx, cnt); // for the last 1
        return mx;
    }
};
```
