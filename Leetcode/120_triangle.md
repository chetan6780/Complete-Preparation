# [120. Triangle](https://leetcode.com/problems/triangle/) 🌟🌟

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

### Dynamic Programming

- [Video](https://www.youtube.com/watch?v=O2eaAdBpZBQ)

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
