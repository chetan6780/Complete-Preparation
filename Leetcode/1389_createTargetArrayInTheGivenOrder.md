# [1389. Create Target Array in the Given Order](https://leetcode.com/problems/create-target-array-in-the-given-order/)

Given two arrays of integers nums and index. Your task is to create target array under the following rules:

- Initially target array is empty.
- From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
- Repeat the previous step until there are no elements to read in nums and index.
- Return the target array.

It is guaranteed that the insertion operations will be valid.

### O(N^2) Time Solution

- Brute force

### Code

```cpp
class Solution{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            ans.insert(ans.begin() + index[i], nums[i]);
        return ans;
    }
};
```

### O(NlogN) based on "smaller elements after self".

- It is HARD level problem
- Will be added soon...
