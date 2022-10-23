# [Chocolate Pickup](https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0) 🌟🌟🌟

This problem is similar to [leetcode cherry pickup II](https://leetcode.com/problems/cherry-pickup-ii/)

### Conventions

-   😂 It is tough to find good variable name, and I don't want to write big variable names, so here are convension for understanding.
-   `aj`: Alice's j'th index
-   `bj`: bob's j'th index
-   `dirAj`: directions for Alice
-   `dirBj`: directions for Bob

### Recursive Solution

-   It is given that alice will be starting from top-left and bob will be starting from top-right, so we have stable starting indexes.
-   They start from top and travels in 3 directions, so they can go in out of bound situation, we need to have check for it.
-   Also when they reach to bottom position we need to check if they are on the same block or not.
    -   If they are at same block we return element only one time.
    -   else we return sum of both the elements where they are standing.
-   Set `mx` to maximum interger value.
-   When `alice` will be at one position there are 3 postions possible of `bob` `(j-1,j,j+1)` and in total `alice` can also be at 3 different place like `bob`. So total we have `3*3 = 9` conditions where they can be situated.
-   We can write 2 nested loop above process.
-   Now while traveling they can be at same column, so total value there will be `grid[i][j]`.
-   And when they are at different position total value will be `grid[i][aj] + grid[i][bj]`.
-   Recurr for updated position of `alice` and `bob` and add it to the value.
-   update maximum value from `mx` and `val`.
-   Return `mx`.

### Code

```cpp
int f(vector<vector<int>>& grid, int r, int c, int i, int aj, int bj)
{
    if (aj < 0 || bj < 0 || aj >= c || bj >= c) return INT_MIN;

    if (i == r - 1) {
        if (aj == bj) return grid[i][aj];
        return grid[i][aj] + grid[i][bj];
    }

    int mx = INT_MIN;
    for (int dirAj = -1; dirAj <= 1; dirAj++) {
        for (int dirBj = -1; dirBj <= 1; dirBj++) {
            int val = 0;
            if (aj == bj)
                val = grid[i][aj];
            else
                val = grid[i][aj] + grid[i][bj];

            val += f(grid, r, c, i + 1, aj + dirAj, bj + dirBj);
            mx = max(mx, val);
        }
    }

    return mx;
}
int maximumChocolates(int r, int c, vector<vector<int>>& grid)
{
    return f(grid, r, c, 0, 0, c - 1);
}
```

### Memoization

-   The recursive soltuion is very slow, so we need to use memoization to avoid unnecessory calculations and reduce overall time complexity.
-   **TC: O(R\*C\*C)**
-   **SC: O(R\*C\*C)**

### Code

```cpp
int f(vector<vector<int>>& grid, int r, int c, int i, int aj, int bj, vector<vector<vector<int>>>& dp)
{
    if (aj < 0 || bj < 0 || aj >= c || bj >= c)
        return INT_MIN;

    if (i == r - 1) {
        if (aj == bj)
            return grid[i][aj];
        return grid[i][aj] + grid[i][bj];
    }

    if (dp[i][aj][bj] != -1)
        return dp[i][aj][bj];

    int mx = INT_MIN;
    for (int dirAj = -1; dirAj <= 1; dirAj++) {
        for (int dirBj = -1; dirBj <= 1; dirBj++) {
            int val = 0;
            if (aj == bj)
                val = grid[i][aj];
            else
                val = grid[i][aj] + grid[i][bj];

            val += f(grid, r, c, i + 1, aj + dirAj, bj + dirBj, dp);
            mx = max(mx, val);
        }
    }

    return dp[i][aj][bj] = mx;
}
int maximumChocolates(int r, int c, vector<vector<int>>& grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(grid, r, c, 0, 0, c - 1, dp);
}
```

### Tabulation

-   To reduce the recursive stack space we use tabulation.
-   Look at the base case of memoization, at last row we were returning the values of element or there addtion based on alice and bobs postition.
-   So fill last row of `dp` accordingly.
-   In memoization `i` were going from 0 to n - 2, now in tabluatoin we will go from n - 2 to 0.
-   `aj` and `bj` will be from 0 to c - 1.
-   now copy recursive relation code and just write `dp` instead of calling recursive function.
-   **One catch** here is, new directions can go out of bound, so we need to check for it.
-   If they go out of bound we add `INT_MIN` to `dp` value.
-   In memoization wee were returning `f(0,0,n-1)` here return `dp[0][0][c-1]`.
-   **TC: O(R\*C\*C)**, dirAj and dirBj are constant.
-   **SC: O(R\*C\*C)**

### Code

```cpp
int maximumChocolates(int r, int c, vector<vector<int>>& grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    for (int aj = 0; aj < c; aj++) {
        for (int bj = 0; bj < c; bj++) {
            if (aj == bj)
                dp[r - 1][aj][bj] = grid[r - 1][aj];
            else
                dp[r - 1][aj][bj] = grid[r - 1][aj] + grid[r - 1][bj];
        }
    }

    for (int i = r - 2; i >= 0; i--) {
        for (int aj = 0; aj < c; aj++) {
            for (int bj = 0; bj < c; bj++) {
                int mx = INT_MIN;
                for (int dirAj = -1; dirAj <= 1; dirAj++) {
                    for (int dirBj = -1; dirBj <= 1; dirBj++) {
                        int val = 0;
                        if (aj == bj) val = grid[i][aj];
                        else val = grid[i][aj] + grid[i][bj];

                        // check for out of bound
                        if (aj + dirAj >= 0 && aj + dirAj < c && bj + dirBj >= 0 && bj + dirBj < c)
                            val += dp[i + 1][aj + dirAj][bj + dirBj];
                        else
                            val += INT_MIN;

                        mx = max(mx, val);
                    }
                }
                dp[i][aj][bj] = mx;
            }
        }
    }
    return dp[0][0][c - 1];
}
```

### Space optimization

-   If we notice we just need `front` to calculate `current` row.
-   ```
    front = dp[i+1]
    current = dp[i]
    ```
-   **TC: O(R\*C\*C)**
-   **SC: O(C\*C)**

### Code

```cpp
int maximumChocolates(int r, int c, vector<vector<int>>& grid)
{
    vector<vector<int>> front(c,vector<int>(c,0)), curr(c,vector<int>(c,0));

    for (int aj = 0; aj < c; aj++) {
        for (int bj = 0; bj < c; bj++) {
            if (aj == bj)
                front[aj][bj] = grid[r - 1][aj];
            else
                front[aj][bj] = grid[r - 1][aj] + grid[r - 1][bj];
        }
    }

    for (int i = r - 2; i >= 0; i--) {
        for (int aj = 0; aj < c; aj++) {
            for (int bj = 0; bj < c; bj++) {
                int mx = INT_MIN;
                for (int dirAj = -1; dirAj <= 1; dirAj++) {
                    for (int dirBj = -1; dirBj <= 1; dirBj++) {
                        int val = 0;
                        if (aj == bj) val = grid[i][aj];
                        else val = grid[i][aj] + grid[i][bj];

                        if (aj + dirAj >= 0 && aj + dirAj < c && bj + dirBj >= 0 && bj + dirBj < c)
                            val += front[aj + dirAj][bj + dirBj];
                        else
                            val += INT_MIN;

                        mx = max(mx, val);
                    }
                }
                curr[aj][bj] = mx;
            }
        }
        front = curr;
    }
    return front[0][c - 1];
}
```
