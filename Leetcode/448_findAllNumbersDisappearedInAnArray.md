# [448. Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) 🌟

-   **GOOGLE, MICROSOFT**

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

### Brute force

-   For each number in the range [1,n], check if it is in the array.
-   If not then add it in the result array.
-   **TC: O(N^2)**
-   **SC: O(1)**

### Sort + search

-   Sort the array.
-   Then we can binary search the missing numbers OR linearly compare 2 adjacent numbers.
-   **TC: O(NlogN)**
-   **SC: O(1)**

### Hash set

-   We can store the value of each number in the array in a hash set.
-   Then we can iterate over the range [1,n] and check if the number is in the hash set.
-   **TC: O(N)**
-   **SC: O(N)**

### Space-Optimized using In-place modification

-   We mark the present element as negative.
-   then we iterate from [1,n] and check if there is `number > 0`, if its present then we add it in the answer array.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(auto x: nums) {
            int curr = abs(x);
            nums[curr-1] = - abs(nums[curr-1]);
        }
        vector<int> ans;
        for(int i = 0; i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
```
