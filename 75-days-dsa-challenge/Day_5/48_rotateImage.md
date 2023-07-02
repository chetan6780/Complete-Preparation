# [48. Rotate Image](https://leetcode.com/problems/rotate-image/) 🌟🌟

### O(N^2) Time and O(N^2) space Solution

-   We can take 1 more 2D matrix and perform the operation
-   But this is not allowed.

### O(N^2) Time O(1) Space Solution

-   Clockwise 90deg rotation
    1. Reverse the matrix.
    2. Transpose the matrix.

### Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size(),m = matrix[0].size();
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < m; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};
```
