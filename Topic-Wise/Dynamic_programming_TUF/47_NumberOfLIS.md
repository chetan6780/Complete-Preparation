# [Number of Longest Increasing Subsequence](https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟

### Solution

-   If we notice dp array of LIS, we can see that if we encounter same length of LIS, we can add the number of LIS of previous element to the current element.
-   **TC: O(n^2)**
-   **SC: O(n)**

### Code

```cpp
int findNumberOfLIS(vector<int>& arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> cnt(n, 1); // Stores the count of LIS ending at i
    int maxLen = 1;
    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (arr[prev] < arr[i]) {
                if (dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev]; // Give count
                }
                else if (dp[prev] + 1 == dp[i]) { // Added this condition
                    cnt[i] += cnt[prev];
                }
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLen) {
            ans += cnt[i]; // Add all LIS ending at i
        }
    }
    return ans;
}
```
