# [Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/) 🌟

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

### Solution

-   We can check if the slope of any two points is equal or not.
-   If the slope is equal, then the points are on the same line.
-   `Slope = (y2 - y1) / (x2 - x1) = dy / dx`, where `dy = y2 - y1, dx = x2 - x1`
-   For line to be straight, slope of any two points should be equal, i.e.
    ` => (y3-y1)/(x3-x1) = (y2-y1)/(x2-x1)`
    ` => (y3-y1)*(x2-x1) = (y2-y1)*(x3-x1)`
    ` => dx*(y3-y1) = dy*(x3-x1)`
-   So we need to check if `dy*(x3-x1) = dx*(y3-y1)` for all points.
-   **TC: O(N)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c)
    {
        int n = c.size();
        int x1 = c[0][0], x2 = c[1][0];
        int y1 = c[0][1], y2 = c[1][1];
        int dy = y2 - y1, dx = x2 - x1;

        for (int i = 2; i < n; i++) {
            int x3 = c[i][0], y3 = c[i][1];
            if (dy * (x3 - x1) != dx * (y3 - y1))
                return false;
        }
        return true;
    }
};
```
