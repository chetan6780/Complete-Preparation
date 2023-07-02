# [1. Two Sum](https://leetcode.com/problems/two-sum/) (Easy)

### O(N^2) Time Constant space

-   Brute force - check every pair of numbers.

### Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if( nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
```

### O(N) Time and O(N) space

-   The basic idea is to maintain a hash table for each element num in nums
-   using num as key and its index (0-based) as value. For each num, search for target - num in the hash table.
-   If it is found and is not the same element as num, then we are done.

### Code

```cpp
class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int num = target - nums[i];
            if (mp.find(num) != mp.end()) return {i, mp[num]};
            mp[nums[i]] = i;
        }
        return {};
    }
};
```
