# [974. Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) (Medium)

### Hashmap Solution

-   We keep adding the sum of elements and store the frequency of sum % modulo k in hashmap.
-   If We found same remainder in the hashmap we can add their prev frequency in count.then increase the frequency of remainder.
-   **TC:O(N)**
-   **SC:O(N)**

### Code

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int mod = (sum % k + k) % k;
            cnt += mp[mod];
            mp[mod]++;
        }
        return cnt;
    }
};
```
