# [867. Transpose Matrix](https://leetcode.com/problems/transpose-matrix/) 🌟

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

### O(N\*M) Time and O(N\*M) space

- Get no of rows and columns of given matrix.
- Create a new matrix of with no.rows=no.columns and no.columns=no.rows.
- Iterate over the matrix and copy the values from the given matrix to the new matrix `ans[j][i]=matrix[i][j]`;
- Space can be optimizes in case of square matrix, where we can use in place swapping of rows and columns.

### Code

```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans(m,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][i]=matrix[i][j];
            }
        }
        return ans ;
    }
};
```
