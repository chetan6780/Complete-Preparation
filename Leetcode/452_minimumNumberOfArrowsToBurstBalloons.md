# [452. Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) 🌟🌟

There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

### Solution

-   sort the array by ending points i.e.(a[1] < b[1])
-   if start of first array is greater than the minEnd then increase the count and set minEnd = end of first array.
-   else set minEnd = min(minEnd, end of first array)
-   finally, return count + !points.empty()

```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0, minEnd = INT_MAX;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        for (auto& p : points) {
            if (p[0] > minEnd) {
                count++;
                minEnd = p[1];
            } else
                minEnd = min(minEnd, p[1]);
        }
        return count + !points.empty();
    }
};
```
