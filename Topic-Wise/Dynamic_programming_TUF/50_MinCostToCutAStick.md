# [Minimum cost to cut a stick](https://www.codingninjas.com/codestudio/problems/cost-to-cut-a-chocolate_3208460?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos) 🌟🌟🌟

### Recursive approach

-   Push 0 and n in cuts array and sort it.
-   We can have cut at any index from i to j and find the minimum cost.
-   cost = cost at j+1 - cost at i-1.
-   total cost = left + right + cost, find minimum total cost and return it.

### Code

```cpp
int f(vector<int>& cuts, int i, int j)
{
    if (i > j) return 0;

    int mn = INT_MAX;
    for (int k = i; k <= j; k++) {
        int left = f(cuts, i, k - 1);
        int right = f(cuts, k + 1, j);
        int cost = left + right + cuts[j + 1] - cuts[i - 1];
        mn = min(mn, cost);
    }
    return mn;
}
// n = total numbers, c = no. of cuts
int cost(int n, int c, vector<int>& cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    return f(cuts, 1, c);
}
```

### Memoization(top-down)

-   Memoize the function recursive code.
-   **TC: O(n^3)**
-   **SC: O(n^2)**

```cpp
int f(vector<int>& cuts, int i, int j, vector<vector<int>>& dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mn = INT_MAX;
    for (int k = i; k <= j; k++) {
        int left = f(cuts, i, k - 1, dp);
        int right = f(cuts, k + 1, j, dp);
        int cost = left + right + cuts[j + 1] - cuts[i - 1];
        mn = min(mn, cost);
    }
    return dp[i][j] = mn;
}
int cost(int n, int c, vector<int>& cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return f(cuts, 1, c, dp);
}
```

### Tabulation(bottom-up)

-   **TC: O(n^3)**
-   **SC: O(n^2)**

```cpp
int cost(int n, int c, vector<int>& cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for (int i = c; i >= 1; i--) {
        for (int j = 1; j <= c; j++) {
            if (i > j)
                continue;
            int mn = INT_MAX;
            for (int k = i; k <= j; k++) {
                int left = dp[i][k - 1];
                int right = dp[k + 1][j];
                int cost = left + right + cuts[j + 1] - cuts[i - 1];
                mn = min(mn, cost);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][c];
}
```
