# [Burst Balloons](https://www.codingninjas.com/codestudio/problems/mining-diamonds_4244494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟🌟

### Recursive Approach 

-   Watch [striver's video](https://www.youtube.com/watch?v=Yz4LlDSlkns&feature=youtu.be) for explanation

```cpp
int f(vector<int> &a, int i, int j ){
    if(i>j) return 0;
    int mx = INT_MIN;
    for(int ind = i; ind<=j; ind++){
        int left = f(a, i, ind-1);
        int right = f(a, ind+1, j);
        int cost = left + right + a[i-1]*a[ind]*a[j+1];
        mx = max(mx, cost);
    }
    return mx;
}
int maxCoins(vector<int>& a)
{
    int n = a.size();
    a.insert(a.begin(), 1);
    a.push_back(1);
    return f(a, 1, n);
}
```

### Memoization(top-down)

-   **TC: O(n^3)**
-   **SC: O(n^2)**

```cpp
int f(vector<int>& a, int i, int j, vector<vector<int>>& dp)
{
    if (i > j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int mx = INT_MIN;
    for (int ind = i; ind <= j; ind++) {
        int left = f(a, i, ind - 1, dp);
        int right = f(a, ind + 1, j, dp);
        int cost = left + right + a[i - 1] * a[ind] * a[j + 1];
        mx = max(mx, cost);
    }
    return dp[i][j] = mx;
}
int maxCoins(vector<int>& a)
{
    int n = a.size();
    a.insert(a.begin(), 1);
    a.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    return f(a, 1, n, dp);
}
```

### Tabulation(bottom-up)

-   **TC: O(n^3)**
-   **SC: O(n^2)**

```cpp
int maxCoins(vector<int>& a)
{
    int n = a.size();
    a.insert(a.begin(), 1);
    a.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for(int i = n; i>=1; i--){
        for(int j = i; j<=n; j++){
            int mx = INT_MIN;
            for(int ind = i; ind<=j; ind++){
                int left = dp[i][ind-1];
                int right = dp[ind+1][j];
                int cost = left + right + a[i-1]*a[ind]*a[j+1];
                mx = max(mx, cost);
            }
            dp[i][j] = mx;
        }
    }
    return dp[1][n];
}
```
