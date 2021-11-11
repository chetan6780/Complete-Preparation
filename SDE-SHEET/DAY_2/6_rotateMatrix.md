# [48. Rotate Image](https://leetcode.com/problems/rotate-image/) 🌟🌟

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

### O(N^2) Time and O(N^2) space Solution

-   We can take 1 more 2D matrix and perform the operation
-   But this is not allowed.

### O(N^2) Time O(1) Space Solution

-   Clockwise 90deg rotation
    1. Reverse the matrix.
    2. Transpose the matrix.

```
 clockwise rotate
 first reverse up to down, then swap the symmetry
 1 2 3     7 8 9     7 4 1
 4 5 6  => 4 5 6  => 8 5 2
 7 8 9     1 2 3     9 6 3
```

-   Anticlockwise 90deg rotation
    1. Transpose the matrix
    2. Rotate the matrix.

```
Anticlockwise rotate
 first swap the symmetry, then reverse up to down
 1 2 3     1 4 7     3 6 9
 4 5 6  => 2 5 8  => 2 5 8
 7 8 9     3 6 9     1 4 7
```

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

### READ

-   [A common method to rotate the image](https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image)
