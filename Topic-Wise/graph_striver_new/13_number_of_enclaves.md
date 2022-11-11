# Number of enclaves

-   [GFG](https://practice.geeksforgeeks.org/problems/number-of-enclaves/1)
-   [Leetcode](https://leetcode.com/problems/number-of-enclaves/description/)

### BFS Solution

-   **TC: O(m\*n)**
-   **SC: O(m\*n)**

### Code

```cpp
class Solution {
    vector<pair<int, int>> dirs = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int i = 0; i< n; i++){
            for (int j = 0; j< m ; j++){
                // first row , first col, last row, last col
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = true;
                    }
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto dir: dirs){
                int nr = r + dir.first;
                int nc = c + dir.second;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc]){
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for(int j = 0; j< m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    res++;
                }
            }
        }

        return res;
    }
};
```
