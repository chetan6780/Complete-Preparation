# [79. Word search](https://leetcode.com/problems/word-search/)

### Backtracking

-   We traverse all the four directions from the current position, to search the word.
-   use visited to avoid revisiting the same position.

### Code

```cpp
class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& s, int i, int j, int k, vector<vector<int>>& vis)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || vis[i][j] == 1)
            return false;
        if (board[i][j] != s[k])
            return false;
        if (k == s.size() - 1)
            return true;

        vis[i][j] = 1;
        if (dfs(board, s, i + 1, j, k + 1, vis) ||
            dfs(board, s, i - 1, j, k + 1, vis) ||
            dfs(board, s, i, j + 1, k + 1, vis) ||
            dfs(board, s, i, j - 1, k + 1, vis))
            return true;
        vis[i][j] = 0;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(board, word, i, j, 0, vis))
                    return true;
        return false;
    }
};
```
