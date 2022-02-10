# [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) 🌟🌟

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

### Brute force (TLE)

-   We can find all subarrays and count subarrays with sum equal to k.
-   **TC: O(n^3)**
-   **SC: O(1)**

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int sm = 0;
                for (int k = i; k < j; k++)
                    sm += nums[k];
                if (sm == k)
                    cnt++;
            }
        }
        return cnt;
    }
};
```

### prefix sum (TLE)

-   Better Brute Force.
-   In the 3rd loop we are finding the sum of the subarray.
-   We can optimize 3rd loop by prefix sum.
-   Store the prefix sum of array elements.
-   While traversing array `if(prefix[j] - prefix[i]==k)` increment the count.
-   return the count.
-   **TC: O(n^2)**
-   **SC: O(n)**

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        // prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (prefix[j] - prefix[i] == k)
                    ans++;
            }
        }
        return ans;
    }
};
```

### Running sum (TLE)

-   Instead of using prefix array to store the prefix sum, we can find the running sum.
-   If sum=k increment the count.
-   Return the count.
-   **TC: O(n^2)**
-   **SC: O(1)**

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
};
```

### Using hashmap (AC)

-   Below explanation is from [LeetCode Discuss](<https://leetcode.com/problems/subarray-sum-equals-k/discuss/535507/Explanation-to-why-map.get(sum-k)-is-done-than-count%2B%2B>).
-   Consider the below example:
    array : `3 4 7 -2 2 1 4 2`
    presum : `3 7 14 12 14 15 19 21`
    index : `0 1 2 3 4 5 6 7`
    k = `7`
    Map should look like :
    `(0,1) , (3,1), (7,1), (14,2) , (12,1) , (15,1) , (19,1) , (21,1)`

-   Consider `21(presum)` now what we do is `sum-k` that is `21-7 = 14`. Now we will check our map if we go by just count++ logic we will just increment the count once and here is where we go wrong.

-   When we search for `14` in presum array we find it on `2` and `4` index. The logic here is that `14 + 7 = 21` so the array between indexes
    -> `3` to `7` `(-2 2 1 4 2)`
    -> `5` to `7` both have sum 7 `( 1 4 2)`
    The sum is still `7` in this case because there are negative numbers that balance up for. So if we consider `count++` we will have one count less as we will consider only array `5` to `7` but now we know that `14` sum occured earlier too so even that needs to be added up so `map.get(sum-k)`.

-   Another way of understanding this is that if there is increase of `k` in the presum array we have found a new subarray so that is why we look for `currentSum-k`.
-   **TC: O(n)**
-   **SC: O(n)**

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        int sm = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1; // getting 0 sum is always possible
        for (int i = 0; i < n; ++i) {
            sm += nums[i];
            if (mp.count(sm - k)) ans += mp[sm - k];
            mp[sm]++;
        }
        return ans;
    }
};
```
