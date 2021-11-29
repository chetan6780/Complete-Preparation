# [733. Flood Fill](https://leetcode.com/problems/flood-fill/) 🌟

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

### DFS - Recursive

-   **Main function:**

    -   if current color is not new color, call the dfs algorithm.
    -   else return original image.

-   **DFS function:**

    -   check for invalid row and column numbers.
    -   check if current color is not old color or is already new color.
    -   for both the cases return.
    -   set current color to new color.
    -   call the function for all the 4 directions.

-   **Complexity:**

    -   Time: **O(M \* N)**, where `M <= 50` is number of rows, `N <= 50` is number of columns in the matrix.
    -   Space: **O(M \* N)**, it's the depth stack memory, in worst case is **O(M \* N)**, can check this discussion on [stackoverflow](https://stackoverflow.com/a/50912382/4084297).

### Code

```cpp
class Solution{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
        if (image[sr][sc] != newColor)
            dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

private:
    void dfs(vector<vector<int>> &imgs, int r, int c, int newColor, int oldColor){
        // invalid row or column
        if (r < 0 || c < 0 || r >= imgs.size() || c >= imgs[0].size()) return;
        // current color is not old color or is already new color
        if (imgs[r][c] != oldColor || imgs[r][c] == newColor) return;

        imgs[r][c] = newColor; // for next we can also use dirs vector.
        dfs(imgs, r - 1, c, newColor, oldColor); // up
        dfs(imgs, r + 1, c, newColor, oldColor); // down
        dfs(imgs, r, c - 1, newColor, oldColor); // left
        dfs(imgs, r, c + 1, newColor, oldColor); // right
    }
};
```

---

### BFS - Iterative

-   **Main function:BFS**

    -   if current color is already new color, return original image
    -   We need a 2D direction vector and a queue for BFS (q of pairs).
    -   push starting point in the queue.
    -   while queue is not empty run loop.
        -   get the row and column index form the front of the queue, and pop it.
        -   set current color to new color
        -   for all directions push {r,c} in the queue if it's valid.

-   **Complexity:**

    -   Time: **O(M \* N)**, where `M <= 50` is number of rows, `N <= 50` is number of columns in the matrix.
    -   Space: **O(M \* N)**, it's the depth stack memory, in worst case is **O(M \* N)**, can check this discussion on [stackoverflow](https://stackoverflow.com/a/50912382/4084297).

### Code

```cpp
class Solution{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
        int currColor = image[sr][sc];
        // if current color is already new color, return original image
        if (currColor == newColor) return image;

        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // directions vector

        queue<pair<int, int>> q; // queue for bfs
        q.push({sr, sc}); // push starting point
        // while queue is not empty run loop.
        while (!q.empty()){
            // get the row and column index form the front of the queue, and pop it.
            int row = q.front().first, col = q.front().second;
            q.pop();

            // set current color to new color
            image[row][col] = newColor;
            // for all directions push {r,c} in the queue if it's valid.
            for (auto &x : dirs){
                int r = row + x.first, c = col + x.second;
                if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || image[r][c] != currColor)
                    continue;
                q.push({r, c});
            }
        }
        return image;
    }
};
```

### MUST READS:

-   [How do you think about solving a question using DFS [ Learn before you Code ]](https://leetcode.com/problems/flood-fill/discuss/442143/How-do-you-think-about-solving-a-question-using-DFS-Learn-before-you-Code)

-   [[C++] standard solution, schema you can apply to other tasks: list + visited](https://leetcode.com/problems/flood-fill/discuss/627915/C%2B%2B-standard-solution-schema-you-can-apply-to-other-tasks%3A-list-%2B-visited)
