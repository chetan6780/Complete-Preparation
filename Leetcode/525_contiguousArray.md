# [525. Contiguous Array](https://leetcode.com/problems/contiguous-array/) 🌟🌟

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

### Brute Force (TLE)

-   We will try all subarrays, and count the number of zeros and ones in each subarray.
-   When the number of zeros and ones are equal, that means we can update our max count.
-   **Time Complexity: O(n^2)**
-   **Space Complexity: O(1)**

### Code

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        int n = nums.size();
        int zeros = 0, ones = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            zeros = 0, ones = 0;
            for (int j = i; j < n; j++) {
                nums[j] == 0 ? zeros++ : ones++;
                if (zeros == ones) mx = max(mx, j - i + 1);
            }
        }
        return mx;
    }
};
```

### hashmap (AC)

-   We can optimize brute force with hashmap.
-   We increment the count by 1 if num is 1 and decrement count by 1 if num is 0.
-   If the count is 0, we know that the subarray from index i to j is a contiguous subarray with equal number of 0s and 1s.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        int n = nums.size();
        int mx = 0, sm = 0;
        unordered_map<int, int> mp;
        mp[0] = -1; // for first element there is no answer
        for (int i = 0; i < n; i++) {
            sm += (nums[i] == 0 ? -1 : 1);
            if (mp.count(sm)) mx = max(mx, i - mp[sm]);
            else mp[sm] = i;
        }
        return mx;
    }
};
```

### READ MORE

-   [[C++] Simplest Solution | Optimization from Brute Force | One-Pass]](https://leetcode.com/problems/contiguous-array/discuss/1743341/C%2B%2B-Simplest-Solution-or-Optimization-from-Brute-Force-or-One-Pass)
