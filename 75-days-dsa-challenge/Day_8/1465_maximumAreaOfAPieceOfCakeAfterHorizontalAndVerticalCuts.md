# [1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/) (Medium)

### Solution

-   We can observe that the answer will always be product of maximum values in horizontal cuts and vertical cuts.
-   We sort the both vectors and then we can find product of maximum values in horizontal cuts and vertical cuts.

### Code

```cpp
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        int n = horizontalCuts.size();
        int m = verticalCuts.size();

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        auto horMax = max(horizontalCuts[0], h - horizontalCuts[n - 1]);
        auto verMax = max(verticalCuts[0], w - verticalCuts[m - 1]);

        for (int i = 0; i < n - 1; i++) {
            horMax = max(horMax, horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        for (int i = 0; i < m - 1; i++) {
            verMax = max(verMax, verticalCuts[i + 1] - verticalCuts[i]);
        }
        return (long)horMax * verMax%1000000007;
    }
};
```
