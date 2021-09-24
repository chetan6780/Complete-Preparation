# [1512. Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if `nums[i] == nums[j]` and i < j.

### O(N^2) Time O(1) Space solution

- Check for each element of array and return the ans.

### Code

```cpp
class Solution{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                    ans++;
            }
        }
        return ans;
    }
};
```

### O(N) Time O(N) Space optimization

- Use map to store if the number appeard before or not.
- If it appeard add frequency to ans.else add it to map.

### Code

```cpp

class Solution{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            ans += mp[nums[i]];
            mp[nums[i]]++;
        }
        return ans;
    }
};

```
