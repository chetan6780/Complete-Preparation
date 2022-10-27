# [Longest Bitonic Sequence](https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟

### Solution

-   Longest Bitonic Sequence is nothing but `max(LIS[i] + LDS[i] - 1)` for all i.
-   **TC: O(n^2)**
-   **SC: O(n)**

### Code

```cpp
int longestBitonicSequence(vector<int>& arr, int n)
{
    // LIS code
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (arr[prev] < arr[i] && dp1[prev] + 1 > dp1[i]) {
                dp1[i] = max(dp1[i], dp1[prev] + 1);
            }
        }
    }
    // Reverse LIS
    vector<int> dp2(n, 1);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int prev = n - 1; prev > i; prev--) {
            if (arr[prev] < arr[i] && dp2[prev] + 1 > dp2[i]) {
                dp2[i] = max(dp2[i], dp2[prev] + 1);
            }
        }
        ans = max(ans, dp1[i] + dp2[i] - 1); // Update answer
    }
    return ans;
}
```
