# [287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

### O(N^2) Brute force

-   check for all numbers if duplicate number exists.

### O(NlogN) Sorting

-   Sort the array and duplicate numbers will be next to each other.

### O(N) Time O(N) space, Hash Table

-   With the help of hash (set/map/vector) we can find the duplicate number.

### Floyd's Cycle Detection Algorithm

```cpp
class Solution{
public:
	int findDuplicate(vector<int> &nums){
		int slow = nums[0];
		int fast = nums[0];

		do{
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);

		fast = nums[0];
		while (slow != fast){
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};
```
