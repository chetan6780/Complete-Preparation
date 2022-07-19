# Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

### Stack Solution

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> st;
        for (int i = 0; i < n; ++i) // Fill left
        {
                while (!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                left[i] = st.empty() ? 0 : st.top() + 1;
                st.push(i);
        }
        st.clear();// Clear stack

        for (int i = n - 1; i >= 0; --i) // Fill right
        {
            if (st.empty()) {
                right[i] = n - 1;
                st.push(i);
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i])
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

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        if (n == 0) return 0;
        int max = 0;
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            if (st.empty() || h >= heights[st.top()]) {
                st.push(i);
            } else {
                int tp = st.top();
                st.pop();
                int w = (st.empty()) ? i : i - st.top() - 1;
                max = max > heights[tp] * w ? max : heights[tp] * w;
                i--;
            }
        }
        return max;
    }
};
```
