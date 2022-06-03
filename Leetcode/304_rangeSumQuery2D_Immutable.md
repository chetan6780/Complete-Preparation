# [304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/) 🌟🌟

### Brute force (TLE)

-   Directly calculate the sum of area.

### Code

```cpp
class NumMatrix {
    vector<vector<int>> arr;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        arr = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i<=row2 ; i++){
            for(int j = col1; j<=col2; j++){
                sum+=arr[i][j];
            }
        }
        return sum;
    }
};
```

### Row Prefix sum (AC)

-   We know the concept of prefix sum for 1D array, we can apply it to 2D array.
-   Calculate prefix sum of each row.
-   From the calculated prefix sum for row, Take only part which is in the area and add it to the answer.
-   Return the answer.

### Code

```cpp
class NumMatrix {
    vector<vector<int>> a;
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        a.resize(n, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = a[i][j - 1] + matrix[i][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = 0;
        for (int i = row1; i <= row2; i++) {
            ans += a[i][col2 + 1] - a[i][col1];
        }
        return ans;
    }
};
```

### Area Prefix sum (AC)

-   Leetcode official solution has very good explanation for this approach.

### Code

```cpp
class NumMatrix {
    vector<vector<int>> a;

public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        a.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return a[row2 + 1][col2 + 1] - a[row2 + 1][col1] - a[row1][col2 + 1] + a[row1][col1];
    }
};
```
