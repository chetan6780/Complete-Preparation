# [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) 🌟🌟🌟

### Solution

-   If we remember past heights of the row we can treat this problem as largest area in histogram problem.
-   If we encounter 1 increase height by 1 else if we encounter 0 reset height to 0.
-   Call largest area in histogram function for each row and return the maximum area.
-   **TC: O(M\*(N+M))**, M = number of rows, N = number of columns
-   **SC: O(M)**, M = number of rows

### Code

```cpp
class Solution {
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? n : n - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};
```
