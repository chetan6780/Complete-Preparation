# [37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) 🌟🌟🌟

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy **all of the following rules**:

1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
   The '.' character indicates empty cells.

### Backtracking (16ms-AC)

-   **Solve function algorithm:**

    -   if index of row exceed the board size, we got our solution, return true.
    -   if index of column exceed the board size, we are done for current row, move to next row.
    -   if current cell is already marked, move to the next cell.

    -   else current cell is empty so we try all characters from '1' to '9' for current cell.
        -   if its valid to put i'th character in current cell,
            -   put i'th character in current cell,
            -   recursively call solve function for next cell,
                -   if it returns true, we got our solution, return true.
                -   else we can not put i'th character in current cell,
            -   remove the i'th character from current cell
    -   if we are done with all characters for current cell, we can not get our solution, return false.

-   **isValid function algorithm:**
    -   check if the current number appeared before in the row.
    -   check if the current number appeared before in the column.
    -   check if the current number appeared before in the 3x3 sub-box.
        -   we can traverse the ith box with,
            ` int newRow = (row / 3) * 3, newCol = (col / 3) * 3;`
            ` int iindex = newRow + i, jindex = newCol + j;`

### Code

```cpp
class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        // row check
        for (int i = 0; i < 9; i++)
            if (board[i][col] == c)
                return false;

        // col check
        for (int i = 0; i < 9; i++)
            if (board[row][i] == c)
                return false;

        // box check
        int newRow = (row / 3) * 3, newCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[newRow + i][newCol + j] == c)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col)
    {
        // done
        if (row == 9) return true;

        // time for next row
        if (col == 9) return solve(board, row + 1, 0);

        // already marked
        if (board[row][col] != '.') return solve(board, row, col + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                // without return here, the board reverts to initial state
                if (solve(board, row, col + 1))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board, 0, 0);
    }
};
```

### Solution-2 (48ms-AC)(striver video)

### Code

```cpp
class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, int num)
    {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num)
                return false;

            if (board[i][col] == num)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') { // empty cell
                    for (char k = '1'; k <= '9'; k++) { // try 1 to 9 characters
                        if (isValid(board, i, j, k)) {
                            board[i][j] = k;

                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    // can't fit any number
                    return false;
                }
            }
        }
        // all cells are filled
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);
    }
};
```
