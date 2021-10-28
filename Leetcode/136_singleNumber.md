# [136. Single Number](https://leetcode.com/problems/single-number/) 🌟

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

### Sorting array

### Using Map

### Using XOR (^)

- XOR of same numbers is 0;
- XOR of 0 with a number is the number;

### Code

```cpp
class Solution{
public:
	int singleNumber(vector<int> &nums){
		int n = nums.size();
		int res = nums[0];
		for (int i = 1; i < n; i++) res ^= nums[i];
		return res;
	}
};
```
