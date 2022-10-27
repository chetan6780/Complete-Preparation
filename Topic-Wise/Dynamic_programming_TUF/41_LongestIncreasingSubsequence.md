# [Longest Increasing Subsequence](https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟

### Recursive solution

-   For this problem we carry 2 indexes, one for current and one for previous element.
-   For an index we have 2 choices, either we can take it or not take it.
-   But to take an element it should be greater than the previous element. or previous element index is -1, i.e. no previous element.
-   If we take current element then add 1 and recur with previous index as current index.
-   Return the max of both the choices.
-   **TC: O(2^n)**
-   **SC: O(n)**, recursive stack space

### Code

```cpp
int f(int* arr, int n, int ind, int prevInd)
{
    if (ind == n) {
        return 0;
    }
    int notTake = f(arr, n, ind + 1, prevInd);
    int take = 0;
    if (prevInd == -1 || arr[ind] > arr[prevInd]) {
        take = 1 + f(arr, n, ind + 1, ind);
    }
    return max(take, notTake);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    return f(arr, n, 0, -1);
}
```

### Memoization(top-down)

-   We can memoize the solution to avoid TLE.
-   Just remember we cannot store -1 index so `prevIndex` will be `prevIndex+1` (1 based indexing).
-   Still give RTE on codestudio because value of `n` is `10^5` so dp array size will be `10^10` which is huge.
-   **TC: O(n^2)**
-   **SC: O(n^2)**

### Code

```cpp
int f(int* arr, int n, int ind, int prevInd, vector<vector<int>>& dp)
{
    if (ind == n) {
        return 0;
    }
    if (dp[ind][prevInd + 1] != -1) {
        return dp[ind][prevInd + 1];
    }
    int notTake = f(arr, n, ind + 1, prevInd, dp);
    int take = 0;
    if (prevInd == -1 || arr[ind] > arr[prevInd]) {
        take = 1 + f(arr, n, ind + 1, ind, dp);
    }
    return dp[ind][prevInd + 1] = max(take, notTake);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(arr, n, 0, -1, dp);
}
```
