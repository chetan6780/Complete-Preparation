# [120. Triangle](https://leetcode.com/problems/triangle/) 🌟🌟

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

### Recursion(TLE)

-   If we are at the last row, return the element.
-   else try going down and right diagonally, take minimum of both.
-   return current element + min of both.

### Code

```cpp
class Solution {
private:
    int helper(vector<vector<int>>& tri, int r, int c)
    {
        if (r == tri.size() - 1)
            return tri[r][c];
        int down = helper(tri, r + 1, c);
        int dig = helper(tri, r + 1, c + 1);
        return tri[r][c] + min(down, dig);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        int ans = helper(triangle, 0, 0);
        return ans;
    }
};
```

### Memoization (AC)

-   The recursive code gives TLE.
-   We can use memoization to solve this problem.
-   Take 2D array memo to store the result.

### Code

```cpp
class Solution {
private:
    int helper(vector<vector<int>>& tri, int r, int c, vector<vector<int>>& memo)
    {
        if (r == tri.size() - 1)
            return tri[r][c];
        if (memo[r][c] != -1)
            return memo[r][c];
        int down = helper(tri, r + 1, c, memo);
        int dig = helper(tri, r + 1, c + 1, memo);
        return memo[r][c] = tri[r][c] + min(down, dig);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        int ans = helper(triangle, 0, 0, memo);
        return ans;
    }
};
```

### Dynamic Programming (AC)

### Code

```cpp
class Solution { // Bottom up solution
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                int mn = min(triangle[i+1][j],triangle[i+1][j+1]);
                int sm = mn + triangle[i][j];
                triangle[i][j]=sm;
            }
        }
        return triangle[0][0];
    }
};
```
