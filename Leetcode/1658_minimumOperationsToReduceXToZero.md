# [1658. Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/) 🌟🌟

### Prefix and Suffix Sum with map

-   Simple - Just think.
<!-- TODO:Explanation  -->

### Sliding Window

-   In the problem its given that we can remove element from start or end to subtract its value form x so that it will become 0. Also we have to minimize the number of such operations.
-   Instead of doing so we can simplify the process.
-   ex.`XXXOOOXX`, here if we need to find `sum of all X` we can simply do it with `total sum - sum of O`, same idea can be used in this problem.
-   We just need to find subarray with `sum = reqSum`, Where `reqSum = totalSumOfArray - x`
-   And we need to **Maximize** the length of such subarray.
-   The answer will be `total length - max length of subarray`
-   **Time Complexity: O(N)**
-   **Space Complexity: O(1)**

### Code

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();

        int reqSum = 0, windowSum = 0;
        reqSum = accumulate(nums.begin(), nums.end(), 0);
        reqSum -= x;
        // if required sum is 0, then total array length is answer.
        if (reqSum == 0) return n;

        int i = 0, maxLen = 0;
        // find sliding window whose sum=reqSum and length is maximum
        for (int j = 0; j < n; j++) {
            windowSum += nums[j];
            while (i < n && windowSum > reqSum) {
                // if window sum exceeds required sum, reduce window size from front
                windowSum -= nums[i];
                i++;
            }
            if (windowSum == reqSum) {
                // we found one of the subarray with required sum
                maxLen = max(maxLen, j - i + 1);
            }
        }

        // if don't find any subarray of required sum, return -1
        if (maxLen == 0) return -1;
        // else return n-maxLen
        return n - maxLen;
    }
};
```
