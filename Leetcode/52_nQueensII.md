# [52. N-Queens II](https://leetcode.com/problems/n-queens-ii/) 🌟🌟🌟

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

### Same problem as [51. N-Queens](./51_nQueens.md), Just need to change result vector with count variable.

**For explanation refer previous question nQueens-1**

### Solution-1 (13ms-AC)

```cpp
class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col)
    {
        int i = row, j = col;
        int n = board.size();
        while (i >= 0 && j >= 0) { // check upper left diagonal
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = row;
        j = col;
        while (i >= 0 && j < n) { // check upper right diagonal
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        for (i = 0; i < n; i++) { // check column
            if (board[i][col] == 'Q')
                return false;
        }
        return true;
    }

    void placeQueen(vector<string>& board, int row, int col)
    {
        board[row][col] = 'Q';
    }

    void removeQueen(vector<string>& board, int row, int col)
    {
        board[row][col] = '.';
    }

    void backtrackNQueen(int& count, vector<string>& board, int row)
    {
        int n = board.size();
        if (row == n) { // row index is out of bounds, we found the solution
            ++count;
            return;
        }

        for (int col = 0; col < n; col++) { // traverse every column
            if (isSafe(board, row, col)) {
                placeQueen(board, row, col); // DO
                backtrackNQueen(count, board, row + 1); // RECUR
                removeQueen(board, row, col); // UNDO
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        backtrackNQueen(count, board, 0);
        return count;
    }
};
```

### Solution-2 (0ms-AC)

```cpp
class Solution {
private:
    bool isSafe(vector<string>& board, vector<int>& colSet, vector<int>& posDig, vector<int>& negDig, int row, int col)
    {
        int n = board.size();
        if (colSet[col] || posDig[col + row] || negDig[col - row + n - 1])
            return false;
        return true;
    }

    void placeQueen(vector<string>& board, vector<int>& colSet, vector<int>& posDig, vector<int>& negDig, int row, int col)
    {
        int n = board.size();
        board[row][col] = 'Q';
        colSet[col] = 1;
        posDig[col + row] = 1;
        negDig[col - row + n - 1] = 1;
    }

    void removeQueen(vector<string>& board, vector<int>& colSet, vector<int>& posDig, vector<int>& negDig, int row, int col)
    {
        int n = board.size();
        board[row][col] = '.';
        colSet[col] = 0;
        posDig[col + row] = 0;
        negDig[col - row + n - 1] = 0;
    }

    void backtrackNQueen(int& count, vector<string>& board, vector<int>& colSet, vector<int>& posDig, vector<int>& negDig, int row)
    {
        int n = board.size();
        if (row == n) { // row index is out of bounds, we found the solution
            ++count;
            return;
        }

        for (int col = 0; col < n; col++) { // traverse every column
            if (isSafe(board, colSet, posDig, negDig, row, col)) {
                placeQueen(board, colSet, posDig, negDig, row, col); // DO
                backtrackNQueen(count, board, colSet, posDig, negDig, row + 1); // RECUR
                removeQueen(board, colSet, posDig, negDig, row, col); // UNDO
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        vector<int> colSet(n, 0);
        vector<int> posDig(2 * n - 1, 0);
        vector<int> negDig(2 * n - 1, 0);

        backtrackNQueen(count, board, colSet, posDig, negDig, 0);

        return count;
    }
};
```

### Solution-3 (3ms-AC)

```cpp
class Solution {
private:
    bool isSafe(vector<int>& flag, int n, int row, int col)
    {
        if (flag[col] == 1 || flag[n + col + row] == 1 || flag[4 * n - 2 + col - row] == 1)
            return false;
        return true;
    }
    void placeQueen(vector<string>& board, vector<int>& flag, int n, int row, int col)
    {
        board[row][col] = 'Q';
        flag[col] = 1;
        flag[n + col + row] = 1;
        flag[4 * n - 2 + col - row] = 1;
    }
    void removeQueen(vector<string>& board, vector<int>& flag, int n, int row, int col)
    {
        board[row][col] = '.';
        flag[col] = 0;
        flag[n + col + row] = 0;
        flag[4 * n - 2 + col - row] = 0;
    }
    void backtrackNQueen(int& count, vector<string>& board, vector<int>& flag, int row)
    {
        int n = board.size();
        if (row == n) {
            ++count;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(flag, n, row, col)) {
                placeQueen(board, flag, n, row, col);
                backtrackNQueen(count, board, flag, row + 1);
                removeQueen(board, flag, n, row, col);
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        vector<int> flag(5 * n - 2, 0);

        backtrackNQueen(count, board, flag, 0);

        return count;
    }
};
```
