# [41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/)

### Set solution

-   We put all non zero positive numbers in a set.
-   We iterate through the array and if the number is not in the set then we return it.

### Code

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        set<int> st;
        for (auto x : nums) {
            if (x > 0)
                st.insert(x);
        }
        int cnt = 1;
        while (st.count(cnt)) {
            cnt++;
        }
        return cnt;
    }
};
```

### O(N) solution

### Code

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```
