# [162. Find Peak Element](https://leetcode.com/problems/find-peak-element/)

### Linear search

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i< n-1;i++){
            if(nums[i]>nums[i+1])return i;
        }
        return n - 1;
    }
};
```

### Binary search

-   We know if array is in ascending order, the peak element is on the right side, and if its in descending order, the peak element is on the left side.
-   Using this knowledge, we can modify binary search to find the peak element.

### Code

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l<r){
            int mid = l + (r - l) / 2;
            if(nums[mid]<nums[mid+1]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};
```
