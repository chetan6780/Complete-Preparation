# [523. Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) 🌟🌟

Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n \* k. 0 is always a multiple of k.

### Brute force

-   Try all possible subarrays and check if the sum is a multiple of k.
-   Will give TLE.
-   **TC: O(n^2)**

### Prefix sum with hash map

-   The intuition is that if we take remainder of subarray A[i:j] with k, and remainder of B[i:j+x] and they both have same remainder, then subarray between j and j+x will have remainder 0.
-   Ex. 23, 2, 4, 6, 7 - here 23 have remainder 5 and 23+2+4 also have remainder 5. So, subarray 2,4 have remainder 0.
-   So we can store indexes of all the remainders that we encounter and if remainder repeats and it has size more than or equal to 2 then we can return true.
-   We can store 0's index as -1 to handle the case when first 2 elements have remainder 0.
-   Else return false.
-   **TC: O(n)**
-   **SC: O(n)**

### Code

```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (mp.count(rem)) {
                if (i - mp[rem] > 1)
                    return true;
            } else {
                mp[rem] = i;
            }
        }
        return false;
    }
};
```
