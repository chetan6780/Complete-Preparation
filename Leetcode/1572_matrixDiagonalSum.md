# [1572. Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/) 🌟

Given a square matrix mat, return the sum of the matrix diagonals.

### O(N) Time O(1) Space solution

- Smart Implimentation😉

### Code

```cpp
class Solution{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size(), ans = 0;
        for (int i = 0; i < n; i++)
            ans += mat[i][i], ans += mat[i][n - 1 - i];
        if (n & 1)
            ans -= mat[n / 2][n / 2];
        return ans;
    }
};
```
