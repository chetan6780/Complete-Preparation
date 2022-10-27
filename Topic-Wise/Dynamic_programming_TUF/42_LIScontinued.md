# [Longest Increasing Subsequence](https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟

### Tabulation(bottom-up)

-   It will also give RTE on codestudio, may pass on leetcode or give TLE.
-   **TC: O(n^2)**
-   **SC: O(n^2)**

### Code

```cpp
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
            int notTake = dp[ind + 1][prevInd + 1];
            int take = 0;
            if (prevInd == -1 || arr[ind] > arr[prevInd]) {
                take = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prevInd + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}
```

### Space optimized tabulation

-   It will also give RTE on codestudio, may pass on leetcode or give TLE.
-   **TC: O(n^2)**
-   **SC: O(n)**

### Code

```cpp
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> next(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
            int notTake = next[prevInd + 1];
            int take = 0;
            if (prevInd == -1 || arr[ind] > arr[prevInd]) {
                take = 1 + next[ind + 1];
            }
            curr[prevInd + 1] = max(take, notTake);
        }
        next = curr;
    }
    return next[0];
}
```

### Algorithmic Approach

-   Still give TLE.
-   But this solution you have to know to print the LIS.
-   `dp[i]` represents the length of the longest increasing subsequence ending at index i.
-   Find the smaller number before current number and add `1` to `dp[prev]`. store max in `dp[i]`.
-   Ex. 5 4 11 1 16 8
    dp 1 1 2 1 3 2
-   **TC: O(N^2)**
-   **SC: O(N)**, only one dp array.

### Code

```cpp
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for(int prev = 0; prev < i; prev++){
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i], dp[prev] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
```

### Print LIS

-   To print LIS, we just index of the element where we have updated the dp.
-   Store that index in idxHash array.
-   We can easily trace back like linked list to get lis. But we get it in reverse order.
-   Reverse the lis and print it.

```cpp
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1),idxHash(n);
    int ans = 1, lastIdx = 0;

    for (int i = 0; i < n; i++) {
        idxHash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(arr[prev] < arr[i]){
                // dp[i] = max(dp[i], dp[prev] + 1);
                if(dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    idxHash[i] = prev;
                }
            }
        }
        // ans = max(ans, dp[i]);
        if(dp[i] > ans){
            ans = dp[i];
            lastIdx = i;
        }
    }
    vector<int> lis;
    lis.push_back(arr[lastIdx]);
    while(lastIdx != idxHash[lastIdx]){
        lastIdx = idxHash[lastIdx];
        lis.push_back(arr[lastIdx]);
    }
    reverse(lis.begin(), lis.end());
    for(int i = 0; i < lis.size(); i++){
        cout << lis[i] << " ";
    }

    return ans;
}
```
