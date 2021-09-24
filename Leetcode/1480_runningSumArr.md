# [1480. Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/) 🌟

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

### O(n) Time and O(n) Space

- Create a sum variable to store current sum in it ans push back it in the result array.

### Code

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};
```

### O(n) Time and O(1) Space

- We can modify input array directy

### Code

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};
```
