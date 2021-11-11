# [73. Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) 🌟🌟

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.You must do it in place.

### Brute Force

-   For every 0 in matrix we set its entire row and column to -1(if all values are positive)
-   after whole matrix is traversed, we set all -1 to 0;
-   **Time Complexity: O(m\*n) \* (m+n)**
    -   m\*n : to traverse the array
    -   m+n : to traverse the row and column for the element.
-   **Space Complexity: O(1)**

### O(m+n) space optimization

-   We take 2 vectors 1 for row and 1 for column.
-   We traverse in matrix and if the element is 0, we set the corresponding row and column vector index to 0.
-   After the traversal, we again traverse the matrix and if any of the row or column vector at that index is 0, we set the element to 0.
-   **Time complexity: 2\*O(N\*M) --> O(N\*M)**

### O(1) Space Optimization

-   Instead of creating 2 new vectors for row and column we can take first row and first column of matrix for marking.
-   We traverse the whole array and if the element is 0, we set the corresponding row and column vector index to 0.
-   For the first col there is one special case, if we set first col to 0 so the row will unnecessarily have 0's in them.
-   to tackle this case we take `col` variable and set it `true` initially. while traversing the array if we got any 0 in first column so we change `col = false`.
-   Now we traverse from bottom-right to top-left and if we found 0 in any marker vector we set current element to 0.
-   for the first column, if `col==false` we set it to 0.
-   **Time complexity: 2\*O(N\*M) --> O(N\*M)**

### Code

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int r = matrix.size(), c = matrix[0].size();
        bool col = true;

        for (int i = 0; i < r; i++) { // Traverse all rows
            if (matrix[i][0] == 0) col = false; // if Element of first column is 0, set col = false
            for (int j = 1; j < c; j++) // Traverse all col
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }

        // traverse from backwards
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) // if any marker array has 0 set i,j th Element to 0
                    matrix[i][j] = 0;
            // if col = false, means whole col is 0.
            if (col == false) matrix[i][0] = 0;
        }
    }
};
```
