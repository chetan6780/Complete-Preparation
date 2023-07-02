# [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) (Easy)

### Naive Solution

-   Store the elements in a set. then add them in the original vector in sorted order.
-   return the size of the set.
-   **TC: O(N log N)**, N for the traversal and log N for inserting elements in the set.
-   **SC: O(N)**, N for the set.

### Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(auto &x: nums) st.insert(x);
        int i=0;
        for(auto &x: st) nums[i++]=x;
        return st.size();
    }
};
```

### 2 pointer solution

-   Place pointe i to start and j to start + 1.
-   If nums[i] == nums[j], increment j.
-   else increment i and set nums[i] = nums[j].
-   return i + 1.
-   **TC: O(N)**, N for the traversal.
-   **SC: O(1)**, since we are modifying the array in place.

### Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size(), i = 0;
        if (n == 0) return 0;
        for (int j = 1; j < n; j++) { // notice: loop is for J
            if (nums[i] != nums[j]) nums[++i] = nums[j];
        }
        return i + 1;
    }
};
```
