# [977. Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)

### O(NlogN) Time solution

- Create new array and push_back squares of each element in it.
- Sort the new array.
- Return the new array.

### Code

```cpp
class Solution{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans;
        for (auto &x : nums)
            ans.emplace_back(x * x);

        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

### O(N) Time solution

- We use two pointer method to solve this problem.
- set two array l=0 and r=arr.size()-1.
- traverse through the array and set max abs values square at last position.
- return the array.

### Code

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int l = 0, r = nums.size()-1;
        int i = nums.size()-1;
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                ans[i--]=nums[l]*nums[l];
                l++;
            }else{
                ans[i--]=nums[r]*nums[r];
                r--;
            }
        }
        return ans;
    }
};
```
