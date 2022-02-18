# [980. Unique Paths III](https://leetcode.com/problems/unique-paths-iii/) 🌟🌟🌟

You are given an `m x n` integer array grid where `grid[i][j]` could be:

```
-> 1 representing the starting square. There is exactly one starting square.
-> 2 representing the ending square. There is exactly one ending square.
-> 0 representing empty squares we can walk over.
->-1 representing obstacles that we cannot walk over.
```

Return the _number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once_.

---

### DFS + Backtracking

- Below solution is explained [here](https://www.youtube.com/watch?v=XNKCkX_tHhM) also on must read no-1.
- We don't need zero++ for backtracking, because it is local variable.

```cpp
class Solution{
private:
    int dfs(vector<vector<int>> &grid, int x, int y, int zero){
        int r = grid.size(), c = grid[0].size();

        if (x < 0 || y < 0 || x >= r || y >= c || grid[x][y] == -1) return 0;
        if (grid[x][y] == 2) return zero == -1 ? 1 : 0;

        // DO
        grid[x][y] = -1;
        zero--;
        // RECUR
        int totalPaths = dfs(grid, x + 1, y, zero) +
                         dfs(grid, x - 1, y, zero) +
                         dfs(grid, x, y + 1, zero) +
                         dfs(grid, x, y - 1, zero);
        // BACKTRACK
        grid[x][y] = 0;

        return totalPaths;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid){
        int zero = 0, sx = 0, sy = 0;
        int r = grid.size(), c = grid[0].size();

        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (grid[i][j] == 0)
                    zero++;
                else if (grid[i][j] == 1){
                    sx = i; //starting x
                    sy = j; //starting y
                }
            }
        }
        return dfs(grid, sx, sy, zero);
    }
};
```

```cpp

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int start_r, int start_c, int zeros)
    {
        if (start_r < 0 || start_r >= r || start_c < 0 || start_c >= c || grid[start_r][start_c] == -1)
            return 0;

        if (grid[start_r][start_c] == 2)
            return zeros == -1 ? 1 : 0;

        // DO
        grid[start_r][start_c] = -1;
        zeros--;

        // RECUR
        int totalPaths = dfs(grid, r, c, start_r + 1, start_c, zeros) + 
        dfs(grid, r, c, start_r - 1, start_c, zeros) + 
        dfs(grid, r, c, start_r, start_c + 1, zeros) + 
        dfs(grid, r, c, start_r, start_c - 1, zeros);

        // UNDO
        grid[start_r][start_c] = 0;
        // zeros++;

        return totalPaths;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int start_r = 0, start_c = 0;
        int zeros = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0)
                    zeros++;
                else if (grid[i][j] == 1) {
                    start_r = i;
                    start_c = j;
                }
            }
        }
        return dfs(grid, r, c, start_r, start_c, zeros);
    }
};
```

### MUST READ

- [Java Easy Solution || DFS + Backtracking || Explanation (Simplified)](<https://leetcode.com/problems/unique-paths-iii/discuss/1553873/Java-Easy-Solution-oror-DFS-%2B-Backtracking-oror-Explanation-(Simplified)>)
- [C++ Simple and Clean DFS Solution, Explained, 0ms Faster than 100%](https://leetcode.com/problems/unique-paths-iii/discuss/1553805/C%2B%2B-Simple-and-Clean-DFS-Solution-Explained-0ms-Faster-than-100)
