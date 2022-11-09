# Flood fill

-   [GFG](https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1)
-   [leetcode](https://leetcode.com/problems/flood-fill/description/)

### DFS solution

-   **TC: O(N\*M)**
-   **SC: O(N\*M)**

### Code

```cpp
class Solution {
    vector<pair<int, int>> dirs = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
    void dfs(vector<vector<int>>& image, int r, int c, int newColor, int initColor, vector<vector<int>>& res)
    {
        res[r][c] = newColor;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i].first;
            int nc = c + dirs[i].second;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == initColor && res[nr][nc] != newColor)
                dfs(image, nr, nc, newColor, initColor, res);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        vector<vector<int>> res = image;
        int initColor = image[sr][sc];
        dfs(image, sr, sc, newColor, initColor, res);
        return res;
    }
};
```
