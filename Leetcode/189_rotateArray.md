# [189. Rotate Array](https://leetcode.com/problems/rotate-array/) 🌟

Given an array, rotate the array to the right by k steps, where k is non-negative.

### O(N) Time and O(N) space

- Create new array
- copy the original array
- Rotate the array by (i+k)%n.

### Code

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(nums.begin(),nums.end());

        // Rotate the elements.
        for(int i=0;i<n;i++){
            nums[(i+k)%n]=temp[i];
        }
    }
};

```

### O(N) Time and O(1) Space

- k%=nums.size(), because if k>n so we need to do only k%n operations.
- reverse the array.
- reverse the first k elements.
- reverse the rest of the array.

### Code

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
```
