# [576. Out of Boundary Paths](https://leetcode.com/problems/out-of-boundary-paths/) 🌟🌟

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

### Recursion (TLE)

-   Trivial DFS: travel in all 4 directions.
-   If we hit the boundary return 1.
-   If we don't have any moves to perform , return 0;
-   **TC: O(4^maxMove)**
-   **SC: O(maxMove)**

```cpp
class Solution {
    vector<vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n)
            return 1;
        if (maxMove == 0)
            return 0;
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int nr = startRow + dirs[i][0];
            int nc = startColumn + dirs[i][1];
            ans += (findPaths(m, n, maxMove - 1, nr, nc) % MOD);
        }
        return ans;
    }
};
```

### Memorization (AC)

-   Use memoization to avoid redundant calculations.
-   **TC: O(n\*m\*maxMove)**
-   **SC: O(n\*m\*maxMove)**

```cpp
class Solution {
    vector<vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    int MOD = 1000000007;

    int helper(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>& memo)
    {
        if (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n)
            return 1;
        if (memo[startRow][startColumn][maxMove] != -1)
            return memo[startRow][startColumn][maxMove];
        if (maxMove == 0)
            return 0;
        long long ans = 0;
        for (auto dir : dirs) {
            int nr = startRow + dir[0];
            int nc = startColumn + dir[1];
            ans += helper(m, n, maxMove - 1, nr, nc, memo) % MOD;
        }
        memo[startRow][startColumn][maxMove] = ans % MOD;
        return memo[startRow][startColumn][maxMove];
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int ans = 0;
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        ans = helper(m, n, maxMove, startRow, startColumn, memo);
        return ans;
    }
};
```

### Tabulation (Bottom-Up) (AC)

-   Memoization to tabulation conversion.
-   **TC: O(n\*m\*maxMove)**
-   **SC: O(n\*m\*maxMove)**
-   `isOutOfBounds()` function returns true if the current position is out of bounds, found this trick in discussion tab.

```cpp
class Solution {
    vector<vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    int MOD = 1000000007;

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        auto isOutOfBounds = [&](int m, int n, int r, int c) { return r < 0 || r >= m || c < 0 || c >= n; };
        vector<vector<vector<uint>>> dp(m, vector<vector<uint>>(n, vector<uint>(maxMove + 1, 0)));
        for (int i = 1; i <= maxMove; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    for (auto dir : dirs) {
                        int r = j + dir[0];
                        int c = k + dir[1];
                        if (isOutOfBounds(m, n, r, c)) {
                            dp[j][k][i]++;
                            dp[j][k][i]%=MOD;
                        } else {
                            dp[j][k][i] += (dp[r][c][i - 1] % MOD);
                        }
                    }
                }
            }
        }
        return dp[startRow][startColumn][maxMove] % MOD;
    }
};
```

### Must Read:

-   **Would an interviewer really care for approach 2 vs 3?** (3rd approach is 2d dp in leetcode solutions tab)(2nd approach is memoization solution written above)
    1.  I believe there is a subtle difference here. It's similar to the knapsack problem, where not every entry of the table is required to be filled in order to compute the final answer. If we use a recursion with memoization for this type of problems, I think it's actually faster (if there are many irrelevant entries), even though recursion creates some overhead. My recursion with memoization solution beat 97% solutions in Python.
    2.  Yes, the recursion solution is probably somewhat faster for most input data but on the other side the approach 3 is easier to debug (e.g. you can print the dp array and detect visually where you went wrong). I think in an interview you should make clear that you are aware of both approaches and then implement the one you feel more comfortable with (or, if you're confident enough, ask the interviewers if they prefer any of them). They probably won't bother about performance since the asymptotical complexity is the same.
        In a real situation, you'll probably take the decision depending on how critical is the process and hence how concerned you are about this performance gain. Also, it's quite likely that the real situation requires several outputs rather than a single one and that the requests arrive in disperse moments. Then it may be useful to precompute all the values incurring an initual cost but guaranteeing an O(1) reponse time after that.
        Long story short, I think the best approach in the interview is to explicitly consider this kind pros and cons (which are quite a standard by the way)
