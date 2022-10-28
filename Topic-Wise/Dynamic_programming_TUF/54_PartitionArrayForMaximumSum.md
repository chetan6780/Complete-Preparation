# [Partition Array for Maximum Sum](https://www.codingninjas.com/codestudio/problems/maximum-subarray_3755255) 🌟🌟

### Recursive Approach

-   Front partition logic.
-   [striver's video](https://www.youtube.com/watch?v=PhWWJmaKfMc) for explanation.

```cpp
int f(int ind, vector<int>& nums, int k)
{
    int n = nums.size();
    if (ind == n)
        return 0;
    int len = 0;
    int mx = INT_MIN, mxAns = INT_MIN;
    for (int j = ind; j < min(ind + k, n); j++) {
        len++;
        mx = max(mx, nums[j]);
        int sum = len * mx + f(j + 1, nums, k);
        mxAns = max(mxAns, sum);
    }
    return mxAns;
}
int maximumSubarray(vector<int>& num, int k)
{
    int n = num.size();
    return f(0, num, k);
}
```

### Memoization

-   **TC: O(N^2)**
-   **SC: O(N)**

```cpp
int f(int ind, vector<int>& nums, int k, vector<int>& dp)
{
    int n = nums.size();
    if (ind == n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int len = 0;
    int mx = INT_MIN, mxAns = INT_MIN;
    for (int j = ind; j < min(ind + k, n); j++) {
        len++;
        mx = max(mx, nums[j]);
        int sum = len * mx + f(j + 1, nums, k, dp);
        mxAns = max(mxAns, sum);
    }
    return dp[ind] = mxAns;
}
int maximumSubarray(vector<int>& num, int k)
{
    int n = num.size();
    vector<int> dp(n + 1, -1);
    return f(0, num, k, dp);
}
```

### Tabulation

-   **TC: O(N^2)**
-   **SC: O(N)**

```cpp
int maximumSubarray(vector<int>& num, int k)
{
    int n = num.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        int len = 0;
        int mx = INT_MIN, mxAns = INT_MIN;
        for (int j = i; j < min(i + k, n); j++) {
            len++;
            mx = max(mx, num[j]);
            int sum = len * mx + dp[j + 1];
            mxAns = max(mxAns, sum);
        }
        dp[i] = mxAns;
    }
    return dp[0];
}
```
