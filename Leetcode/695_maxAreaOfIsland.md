# [695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/) 🌟🌟

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

### DFS - Recursive

- For each cell we check, if it is 1,then we call a bfs on it

- **DFS Function:**

  - we pass grid, i and j in dfs.
  - if the cell is valid we call dfs on its four sides.

- **Complexity:**

  - Time: **O(M \* N)**, where M is number of rows, N is number of columns in the grid.
  - Space: **O(M \* N)**, the space used by the depth stack during our recursion, in worst case is **O(M \* N)**.

### Code - 1

```cpp
class Solution{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid){
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(grid, i, j));
        return ans;
    }

private:
    int dfs(vector<vector<int>> &grid, int i, int j){
        int r = grid.size();
        int c = grid[0].size();
        if (i >= 0 && j >= 0 && i < r && j < c && grid[i][j] == 1){
            grid[i][j] = 0;
            return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j)
                     + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
        }
        return 0;
    }
};
```

### Code - 2

```cpp
class Solution{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid){
        int r = grid.size(), c = grid[0].size(), ans = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(grid, i, j));
        return ans;
    }

private:
    int dfs(vector<vector<int>> &grid, int i, int j){
        int r = grid.size();
        int c = grid[0].size();
        int area = 1;
        vector<int> dir({-1, 0, 1, 0, -1});

        grid[i][j] = 0;

        // dfs on 4 directions
        for (int k = 0; k < 4; k++){
            int nr = i + dir[k], nc = j + dir[k + 1];
            if (nr >= 0 && nc >= 0 && nr < r && nc < c && grid[nr][nc] == 1)
                area += dfs(grid, nr, nc);
        }
        return area;
    }
};
```

---

### BFS - Iterative

- For each cell we check, if it is 1,then we call a **bsf** on it

- **BFS Function**

  - We use q for bfs and push the first pair of i&j in q
  - While q is not empty
  - for top of the queue, we go on four directions and set `grid[nr][nc]=0` and increase the area count.
  - return the area.

- **Complexity:**

  - Time: **O(M \* N)**, where M is number of rows, N is number of columns in the grid.
  - Space: **O(M \* N)**, the space used by the queue in bfs, in worst case is **O(M \* N)**, can check this discussion:[stackoverflow](https://stackoverflow.com/a/50912382/4084297)

### Code

```cpp

class Solution{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid){
        int r = grid.size(), c = grid[0].size(), ans = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 1)
                    ans = max(ans, bfs(grid, i, j));
        return ans;
    }

private:
    int bfs(vector<vector<int>> &grid, int i, int j){
        int r = grid.size();
        int c = grid[0].size();
        int area = 1;
        vector<int> dir({-1, 0, 1, 0, -1});

        grid[i][j] = 0;

        // queue for bfs
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()){
            int z = q.front().first, x = q.front().second;
            q.pop();
            // move in 4 directions
            for (int k = 0; k < 4; k++){
                int nr = z + dir[k], nc = x + dir[k + 1];
                if (nr >= 0 && nc >= 0 && nr < r && nc < c && grid[nr][nc] == 1){
                    grid[nr][nc] = 0;
                    area++;
                    q.push({nr, nc});
                }
            }
        }
        return area;
    }
};

```
