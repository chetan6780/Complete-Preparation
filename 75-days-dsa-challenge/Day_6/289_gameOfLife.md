# [289. Game of Life](https://leetcode.com/problems/game-of-life/) (Medium)

# Simulation

-   Just do what asked to do in the problem.

### code

```cpp
class Solution {
private:
    int getSum(vector<vector<int>>& board, int i, int j)
    {
        int sum = 0;
        // i-1,j
        // i-1,j-1
        // i-1,j+1
        if (i - 1 >= 0) {
            sum += board[i - 1][j];
            if (j - 1 >= 0)
                sum += board[i - 1][j - 1];
            if (j + 1 < board[0].size())
                sum += board[i - 1][j + 1];
        }

        // i+1, j
        // i+1, j-1
        // i+1, j+1
        if (i + 1 < board.size()) {
            sum += board[i + 1][j];
            if (j - 1 >= 0)
                sum += board[i + 1][j - 1];
            if (j + 1 < board[0].size())
                sum += board[i + 1][j + 1];
        }

        // i,j-1
        // i,j+1
        if (j - 1 >= 0)
            sum += board[i][j - 1];
        if (j + 1 < board[0].size())
            sum += board[i][j + 1];

        return sum;
    }

public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int currSum = getSum(board, i, j);
                if (currSum < 2) {
                    ans[i][j] = 0;
                } else if (currSum == 3) {
                    ans[i][j] = 1;
                } else if (currSum > 3) {
                    ans[i][j] = 0;
                } else {
                    ans[i][j] = board[i][j];
                }
            }
        }

        board = ans;
    }
};
```
