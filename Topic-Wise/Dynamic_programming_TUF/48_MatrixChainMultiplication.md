# [Matrix chain multiplication](https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos) 🌟🌟

# Steps

1. Start with entire array.
2. Try all possible partitions.
3. Return the best possible two partitions.

### Recursive Approach

-   Dimensions of i'th matrix are `a[i-1] * a[i]` and j'th matrix are `a[j-1] * a[j]`.
-   if `a[i]==a[j]` then no. of operations are `a[i-1] * a[i] * a[j]`, we want to find minimum of this for all possible partitions of i'th and j'th matrix.
-   We divide the array into two parts and find the minimum of all possible partitions.
-   We can recur k as,
    ```
    1) k=i to j-1 then, recur for i to k , k+1 to j  OR
    2) k=i+1 to j then, recur for i to k-1 , k to j
    ```
-   calculate total steps = first partition + second partition + no. of operations.
-   Update the minimum value.
-   Return the minimum value.

### Code

```cpp
int f(int i, int j, vector<int>& arr)
{
    if (i == j)
        return 0;
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        int first = f(i, k, arr);
        int second = f(k + 1, j, arr);
        int steps = first + second + arr[i - 1] * arr[k] * arr[j];
        mn = min(mn, steps);
    }
    return mn;
}

int matrixMultiplication(vector<int>& arr, int N)
{
    return f(1, N - 1, arr);
}
```

### Memoization(top-down)

-   We can use memoization to reduce the time complexity.
-   For base case we don't need to explicitly assign the value as it is already 0.
-   **TC: O(n^3)**
-   **SC: O(n^2)**

### Code

```cpp
int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        int first = f(i, k, arr, dp);
        int second = f(k + 1, j, arr, dp);
        int steps = first + second + arr[i - 1] * arr[k] * arr[j];
        mn = min(mn, steps);
    }
    return dp[i][j] = mn;
}

int matrixMultiplication(vector<int>& arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N - 1, arr, dp);
}
```
