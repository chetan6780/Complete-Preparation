# [268. Missing Number](https://leetcode.com/problems/missing-number/) 🌟

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

### O(NlogN) by Sorting

- With sorting we can get missing number.

### O(N) Time

- Calculate the sum of all elements in the array.
- Subtract the sum of all elements in the array from the sum of all elements in the range 1 to n.

```cpp
class Solution{
public:
	int missingNumber(vector<int> &nums){
		int sum = 0, n = nums.size();
		for (int i = 0; i < n; i++){
			sum += nums[i];
		}
		return (n * (n + 1) / 2) - sum;
	}
};
```
