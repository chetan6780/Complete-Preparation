# [566. Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix/) 🌟

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

### O(N\*M) Time and O(N\*M)+O(N\*M) Space

- naive approach
- store 2D array in 1D temporary array.
- Create new r\*c matrix and fill it with the values from the temporary array.

### Code

```cpp
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int n=mat.size(),m=mat[0].size();
        if(n*m!=r*c)return mat;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        vector<int> temp(r * c);

        int k = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                temp[k++] = mat[i][j];
            }
        }
        k = 0;
        for (auto &x : ans){
            for (auto &y : x){
                y = temp[k++];
            }
        }
        return ans;
    }
};
```

### O(N\*M) Time and O(N\*M) Space (Row-First Approach

- M[i] => M[i/n][i%n] it will result in right mapping
- `i/c` will give us the row number of output matrix. We will move to New row after every c elements and thus dividing by c will give the row number.
- `i%c` will give us the column number of output matrix. We will be begin from start of new row after every c elements and this the remainder will give column of current row.
- The same happens in i/n and i%n but for the mat matrix).

### Code

```cpp
class Solution{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c){
        int m = mat.size(), n = mat[0].size(), total = m * n;
        if (r * c != total)return mat; // for invalid dimentions

        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < total; i++){
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};
```

### O(N\*M) Time and O(N\*M) Space (Column-First Approach)

<!-- TODO: (Column-First Approach) -->
