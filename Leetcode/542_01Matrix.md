# [542. 01 Matrix](https://leetcode.com/problems/01-matrix/) 🌟🌟

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

### BFS solution

- Firstly, we can see that the distance of all zero-cells are 0.
- Same idea with Topology Sort, we process zero-cells first, then we use queue data structure to keep the order of processing cells, so that cells which have the smaller distance will be processed first. Then we expand the unprocessed neighbors of the current processing cell and push into our queue.
- After all, we can achieve the minimum distance of all cells in our matrix.

**Complexity:**

- Time: `O(M * N)`, where M is number of rows, N is number of columns in the matrix.
- Space: `O(M * N)`, space for the queue.

### Code

```cpp
class Solution{
    vector<int> dirs = {0, 1, 0, -1, 0};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat){
        int r = mat.size(), c = mat[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (mat[i][j] == 0)
                    q.emplace(i, j);
                else
                    mat[i][j] = -1; // mark as not processed
            }
        }

        while (!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++){
                int nr = i + dirs[k], nc = j + dirs[k + 1];
                if (nr < 0 || nc < 0 || nr >= r || nc >= c || mat[nr][nc] != -1)
                    continue;
                mat[nr][nc] = mat[i][j] + 1;
                q.emplace(nr, nc);
            }
        }
        return mat;
    }
};
```

### DP Solution

- Firstly, we can see that the distance of all zero-cells are 0, so we skip zero-cells, we process one-cells only.
- In DP, we can only use previous values if they're already computed.
- In this problem, a cell has at most 4 neighbors that are left, top, right, bottom. If we use dynamic programming to compute the distance of the current cell based on 4 neighbors simultaneously, it's impossible because we are not sure if distance of neighboring cells is already computed or not.
- That's why, we need to compute the distance one by one:
  - Firstly, for a cell, we restrict it to only 2 directions which are left and top. Then we iterate cells from **top to bottom**, and from **left to right**, we calculate the distance of a cell **based on its left and top neighbors**.
  - Secondly, for a cell, we restrict it only have 2 directions which are right and bottom. Then we iterate cells from **bottom to top**, and from **right to left**, we update the distance of a cell **based on its right and bottom neighbors**.

**Complexity:**

- Time: `O(M * N)`, where M is number of rows, N is number of columns in the matrix.
- Space: `O(1)`

### Code

```cpp
class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat){
        int r = mat.size(), c = mat[0].size(), total = r + c;

        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (mat[i][j] == 0) continue;
                int top = total, left = total;
                if (i - 1 >= 0) top = mat[i - 1][j];
                if (j - 1 >= 0) left = mat[i][j - 1];
                mat[i][j] = min(top, left) + 1;
            }
        }

        for (int i = r - 1; i >= 0; i--){
            for (int j = c - 1; j >= 0; j--){
                int bottom = total, right = total;
                if (i + 1 < r) bottom = mat[i + 1][j];
                if (j + 1 < c) right = mat[i][j + 1];
                mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
            }
        }

        return mat;
    }
};

```

### MUST READ:

- [[C++/Java/Python] BFS, DP solutions - with Picture - Clean & Concise - O(1) Space](<https://leetcode.com/problems/01-matrix/discuss/1369741/C%2B%2BJavaPython-BFS-DP-solutions-with-Picture-Clean-and-Concise-O(1)-Space>)
