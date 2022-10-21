# [219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) 🌟

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

### Sliding window + hashmap

-   We know that if there exist any duplicate then it should be in range `abs(i-j) <= k`.
-   So we can create map to store the index of the element.
-   when we encounter the duplicate we can check if the index is in range `abs(i-j) <= k`.
-   If it does `return true` else give the index of the number to the map.
-   Finally `return false` if there is no duplicate in the range.
-   **TC: O(N)**
-   **SC: O(N)**

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i]) && i - mp[nums[i]] <= k)
                return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};
```

### Sliding window + set

-   instead of map we can use set to store the elements.
-   Here we can reduce space complexity to `O(k)`.
-   **TC: O(N)**
-   **SC: O(k)**

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            if (st.count(nums[i])) {
                return true;
            }
            st.insert(nums[i]);
            if (st.size() > k) {
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};
```
