# [1499. Max Value of Equation](https://leetcode.com/problems/max-value-of-equation/)

### Max heap solution

-   Because `xi < xj`, `yi + yj + |xi - xj| = (yi - xi) + (yj + xj)`
-   So for each pair of (xj, yj),
-   we have xj + yj, and we only need to find out the maximum yi - xi.
-   To find out the maximum element in a sliding window, using priority queue or stack.

### Code

```cpp
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k)
    {
        priority_queue<pair<int, int>> pq;
        int ans = INT_MIN;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            // if (xj - xi > k) pop points
            while ((!pq.empty()) && (points[i][0] - pq.top().second > k))
                pq.pop();
            if (!pq.empty()) {
                // maximize the value of equation yi + yj + |xi - xj| = (xj + yj) + (yi - xi)
                // xj and yj are current points i.e. constant (xj + yj)
                // if we can maximize (yi - xi) our equation will automatically become maximum
                // ans = max(ans, xj + yj + pq.top().first[prev max(yi-xi)]);
                ans = max(ans, points[i][0] + points[i][1] + pq.top().first);
            }
            // add new points {yi - xi, xi}
            pq.push({ points[i][1] - points[i][0], points[i][0] });
        }
        return ans;
    }
};
```
