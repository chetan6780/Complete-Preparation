# [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) (Medium)

### Brute force

-   We take hight of individual bars as the height of the rectangle and all the left and right bars that can achieve the height of the current rectangles are included in width.
-   **TC:O(N^2)**
-   **SC:O(1)**

### Stack Solution

-   we store next smaller element from left and right of the element in the vectors using stack.
-   Then we can iterate through them and find maximum area of the rectangle with `right-left+1`.
-   **TC:O(N)**
-   **SC:O(N)**

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> st;
        for (int i = 0; i < n; i++) // Fill left
        {
            if (st.empty()) {
                left[i] = 0;
                st.push(i);
            } else {
                // find index of next smaller element to the left
                while (!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                left[i] = st.empty() ? 0 : st.top() + 1;
                st.push(i);
            }
        }
        while (!st.empty()) // Clear stack
            st.pop();

        for (int i = n - 1; i >= 0; --i) // Fill right
        {
            if (st.empty()) {
                right[i] = n - 1;
                st.push(i);
            } else {
                // find index of next smaller element to the right
                while (!st.empty() and heights[st.top()] >= heights[i])
                    st.pop();
                right[i] = st.empty() ? n - 1 : st.top() - 1;
                st.push(i);
            }
        }

        int mx_area = 0; // Stores max_area
        for (int i = 0; i < n; ++i)
            mx_area = max(mx_area, heights[i] * (right[i] - left[i] + 1));
        return mx_area;
    }
};
```
