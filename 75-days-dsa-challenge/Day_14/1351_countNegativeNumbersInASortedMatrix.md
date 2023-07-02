# [1351. Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/) (Easy)

### Brute force

-   **TC: O(n^2)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] < 0)
                    ans++;
            }
        }
        return ans;
    }
};
```

### Binary search

-   Because the array is sorted we can apply binary search to find the first negative number.
-   **TC: O(nlog(n))**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // binary search
            int l = 0, r = m - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (grid[i][mid] < 0) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans += m - l;
        }
        return ans;
    }
};
```

### Binary search - 2

-   We start from bottom right corner and move towards top left corner to find first negative number.
-   **TC: O(n + m)**
-   **SC: O(1)**

### Code

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int r = n - 1, c = 0;
        while (r >= 0 && c < m) {
            if (grid[r][c] < 0) {
                ans += m - c;
                r--;
            } else {
                c++;
            }
        }
        return ans;
    }
};
```
