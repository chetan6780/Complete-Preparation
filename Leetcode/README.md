# Leetcode problem hints and solutions

#### Difficulty level:
- 🌟 **- Easy**
- 🌟🌟 **- Medium**
- 🌟🌟🌟 **- Hard**

---

# [1920 - Build Array from Permutation](./1920_buildArrayFromPermutation.md) 🌟

### O(n) time and O(n) space solution

- For i=0 to n , simply do what they have asked to.
- Push_back(nums[nums[i]])

### O(n) time and O(1) space optimization

- This is done to keep both old and new value together.
- going by the example of [5,0,1,2,3,4], n = 6(size of array)
- `nums[i] = nums[i]+(n*(nums[nums[i]]%n));`
- after this nums[0] will be 5 + 6\*(4%6) = 5 + 24 = 29;
- now for next index calulation we might need the original value of num[0] which can be obtain by num[0]%6 = 29%6 = 5;
- if we want to get just the new value of num[0], we can get it by num[0]/6 = 29/6 = 4

---
