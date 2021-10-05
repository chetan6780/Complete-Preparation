# [167. Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) 🌟

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= first < second <= numbers.length.

Return the indices of the two numbers, index1 and index2, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

### O(N) Time 2-pointers solution

- We maintain 2 pointers, one at the start and one at the end.
- We itterate over the array.
  - If Sum if equal to target, return the indices.
  - else if sum is greater than target we decrement the end pointer.
  - else we increment the start pointer.

### Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size(),l=0,r=n-1;
        while(l<r){
            if(target==numbers[l]+numbers[r]){
                return {l+1,r+1};
            }else if(target<numbers[l]+numbers[r]){
                r--;
            }else{
                l++;
            }
        }
        return {};
    }
};
```
