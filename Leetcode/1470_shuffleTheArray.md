# [1470. Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/) 🌟

Given the array nums consisting of 2n elements in the form `[x1,x2,...,xn,y1,y2,...,yn]`.
Return the array in the form `[x1,y1,x2,y2,...,xn,yn]`.

### O(N) Time and O(N) Space solution

- Use two pointers to create the new array of 2n elements. The first starting at the beginning and the other starting at (n+1)th position. Alternate between them and create the new array.

### Code

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        int l=0,r=n;
        for(int i=0;i<2*n;i+=2){
            ans[i]=nums[l];
            ans[i+1]=nums[r];
            l++,r++;
        }
        return ans;
    }
};
```
