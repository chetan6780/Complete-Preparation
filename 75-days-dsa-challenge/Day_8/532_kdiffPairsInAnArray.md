# [532. K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/) (Medium)

### Brute force

-   We can traverse every pair of array elements and check if the difference is k.
-   inset the minimum value in the set and return set.size().
-   **TC: O(n^2)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        int n = nums.size();
        set<int> st;
        int a = 0, b = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    st.insert(min(nums[i], nums[j]));
                }
            }
        }
        return st.size();
    }
};
```

### with binary search

-   we can sort the array and find the num+k in the sorted array.
-   **TC: O(nlogn)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        int n = nums.size();
        set<int> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (binary_search(nums.begin() + i + 1, nums.end(), nums[i] + k)) {
                st.insert(nums[i]);
            }
        }
        return st.size();
    }
};
```

### with hashmap

-   we can reduce the time complexity if we store the count of numbers in hashmap.
-   traverse the hash map.
    -   if k>0 and map has num+x in it, increase the count.
    -   if k==0 and num has frequency greater then 1, increase the count
-   return count.
-   **TC: O(n)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        map<int, int> mp;
        for (auto x : nums)
            mp[x]++;

        int res = 0;
        for (auto x : mp) {
            if (k > 0 && mp.count(x.first + k) || k == 0 && x.second > 1)
                res++;
        }
        return res;
    }
};
```
