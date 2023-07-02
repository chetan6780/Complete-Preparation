# [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

### Solution

-   We traverse all 4 directions one by one.
-   we traverse in first direction until we reach the boundary, and then we move to the next direction.
-   Do this process for all 4 directions, and decrease the boundary by 1

### Code

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;
        int cnt = n * m;
        int i = 0, j = 0;
        int vertEnd = 0, horEnd = 0;

        while (cnt) {
            while (j < m && cnt) {
                ans.push_back(matrix[i][j]);
                cnt--;
                j++;
            }
            j--;
            i++;
            while (i < n && cnt) {
                ans.push_back(matrix[i][j]);
                cnt--;
                i++;
            }
            i--;
            j--;
            while (j >= horEnd && cnt) {
                ans.push_back(matrix[i][j]);
                cnt--;
                j--;
            }
            horEnd++;
            j++;
            i--;
            vertEnd++;
            while (i >= vertEnd && cnt) {
                ans.push_back(matrix[i][j]);
                cnt--;
                i--;
            }
            i++;
            j++;
            n--;
            m--;
        }
        return ans;
    }
};
```

### Code - 2

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m - 1, bottom = n - 1, top = 0;
        int direction = 1;
        vector<int> v;
        while (left <= right && top <= bottom) {
            if (direction == 1) {
                for (int i = left; i <= right; i++)
                    v.push_back(matrix[top][i]);
                direction = 2;
                top++;
            }

            else if (direction == 2) {
                for (int i = top; i <= bottom; i++)
                    v.push_back(matrix[i][right]);
                direction = 3;
                right--;
            }

            else if (direction == 3) {
                for (int i = right; i >= left; i--)
                    v.push_back(matrix[bottom][i]);
                direction = 4;
                bottom--;
            }

            else if (direction == 4) {
                for (int i = bottom; i >= top; i--)
                    v.push_back(matrix[i][left]);
                direction = 1;
                left++;
            }
        }
        return v;
    }
};
```

### Code - 3

```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<vector<int>> dirs { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    vector<int> res;
    int nr = matrix.size();
    if (nr == 0)
        return res;
    int nc = matrix[0].size();
    if (nc == 0)
        return res;

    vector<int> nSteps { nc, nr - 1 };

    int iDir = 0; // index of direction.
    int ir = 0, ic = -1; // initial position
    while (nSteps[iDir % 2]) {
        for (int i = 0; i < nSteps[iDir % 2]; ++i) {
            ir += dirs[iDir][0];
            ic += dirs[iDir][1];
            res.push_back(matrix[ir][ic]);
        }
        nSteps[iDir % 2]--;
        iDir = (iDir + 1) % 4;
    }
    return res;
}
```
